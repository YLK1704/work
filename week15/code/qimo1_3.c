#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define TCOUNT 10
#define COUNT_LIMIT 5
#define NUM_THREADS 4
int count = 0;
int thread_ids[4]={0,1,2,3};
int buffer[5];

pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;
pthread_cond_t count_threshold_cv2;


void *inc_count(void *idp)
{
	int *my_id=(int*)idp;
	while(1){
		pthread_mutex_lock(&count_mutex);
		while(count==COUNT_LIMIT)pthread_cond_wait(&count_threshold_cv,&count_mutex);				
		buffer[count]=((int)random())%1000;		
		printf("create%d %d: num %d:\n",*my_id,count,buffer[count]);
		count++;
		pthread_mutex_unlock(&count_mutex);	
		pthread_cond_signal(&count_threshold_cv2);
	}
	pthread_exit(NULL);
}
void *de_count(void *idp)
{
	int i,j;
	int *my_id=(int*)idp;
	int temp;
	while(1){
		pthread_mutex_lock(&count_mutex);		
		while(count==0){
			pthread_cond_wait(&count_threshold_cv2,&count_mutex);
		}		
		temp=buffer[count-1]; //43210
		printf("consum%d %d: num %d:\n",*my_id,(count-1),temp);
		count--;												
		pthread_mutex_unlock(&count_mutex);
		pthread_cond_signal(&count_threshold_cv);
		sleep(1);
	}
	pthread_exit(NULL);
}

int main(int argc,char**argv)
{
	int i,rc;
	pthread_t threads[4];
	pthread_attr_t attr;
	pthread_mutex_init(&count_mutex,NULL);
	pthread_cond_init(&count_threshold_cv,NULL);
	pthread_cond_init(&count_threshold_cv2,NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_create(&threads[0],&attr,inc_count,(void *)&thread_ids[0]);
	pthread_create(&threads[1],&attr,de_count,(void *)&thread_ids[1]);
	pthread_create(&threads[2],&attr,de_count,(void *)&thread_ids[2]);
	pthread_create(&threads[3],&attr,de_count,(void *)&thread_ids[3]);
	for(i=0;i<NUM_THREADS;i++)
		pthread_join(threads[i],NULL);
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	pthread_cond_destroy(&count_threshold_cv2);
	pthread_exit(NULL);
}
