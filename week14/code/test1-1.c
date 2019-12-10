#include"my.h"
void *threadfun(){
	printf("pid=%d :worker thread is runnning!\n",getpid());
}

int main(){
	pthread_t tid;
	int error = pthread_create(&tid,NULL,threadfun,NULL);
	if(error!=0)
	{
		perror("thread create failed!\n");
		return -1;
	}
	printf("master thread pid=%d,work thread tid =%lx\n",getpid(),tid);
	return 0;
}
