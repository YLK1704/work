#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void * thread_function(void *arg) ;
int run_now=1; /*用run now代表共享资源*/
void * thread_function(void *arg) {
	int print_count2=0;
	while (print_count2 ++<5){
		if(run_now==2){ 
			printf ("function thread is run\n") ;
			run_now=1 ;
		}
		else {
		printf("function thread is sleep\n") ;
		sleep(1) ;
		}
	}
	pthread_exit(NULL);
}

int main() {
	int print_count1=0; 
	pthread_t a_thread;
	if(pthread_create (&a_thread,NULL,thread_function,NULL) !=0) {
		perror("Thread createion failed");
		exit(1);
	}
	while (print_count1++<5) {
	if (run_now==1){ /*主线程:如果run_ now为1就把它修改为2*/
		printf("main thread is run\n") ;
		run_now=2;
	}
	else {
	printf ("main thread is sleep\n") ;
	sleep(1) ;
	}
	}
	pthread_join(a_thread,NULL) ; /*等待子线程结束*/
	exit(0);
}
