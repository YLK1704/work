#include"my.h"
#define SIZE 100
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
pthread_rwlock_t rwlock;
int a[SIZE],b[SIZE];
int max=0;

void * max_fun(void * arg)
{
	int *p=(int *)arg;
	int i,k;
	k=0;
	for(i=1;i<SIZE;i++){
		if(p[i]>p[k])
			k=i;
	}
	pthread_rwlock_rdlock(&rwlock);
    pthread_mutex_lock(&mutex);
	printf("%d ",p[k]);
	if(max<p[k]) {
		max=p[k];
	}
    pthread_mutex_unlock(&mutex);
   	pthread_rwlock_unlock(&rwlock);
	pthread_exit(NULL);
}


int main(void)
{
	pthread_t tid1,tid2;
	int i,rv;
	for(i=0;i<SIZE;i++){
		a[i]=rand()%10000;
		b[i]=rand()%10000;
	}
	rv = pthread_create(&tid1,NULL,(void*(*)())max_fun,a);
	rv = pthread_create(&tid2,NULL,(void*(*)())max_fun,b);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	printf("max value=%d\n",max);
	exit(0);
}
