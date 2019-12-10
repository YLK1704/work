#include "my.h"
#define NUM_THREADS 4
struct info{
	int no;
	int n;
};

struct rval{
	int sum;
	pthread_t tid;
};

void hello(void *t)
{
	pthread_t my_tid;
	struct info *y;
	struct rval *r;
	int s=0;
	y=(struct info *)(t);
	for(int i=0;i<=y->n;i++)
		s+=i;
	my_tid =pthread_self();
	printf("\tThread %d: my tid is %lx,Hello world\n",(int)y->no+1,my_tid);
	printf("\tthread %d: sum 1 to %d is %d\n",(int)y->no+1,y->n,s);
	r->sum=s;
	r->tid=pthread_self();
	pthread_exit((void *)r);
}

int main()
{
	pthread_t tid;
	struct info a[4];
	int rv,t;
	void * retval;struct rval * retval2;
	for(t=0;t<NUM_THREADS;t++){
		a[t].no=t;
		a[t].n=100*(t+1);
		rv=pthread_create(&tid,NULL,(void * (*)())hello,(void*)&a[t]);
		pthread_join(tid,&retval);
		if(rv!=0)
		{
			printf("thread create failed!\n");		
			return -1;		
		}
		printf("create thread %lx\n",tid);
		
		retval2=(struct rval *)retval;
		printf("pthread_exit:tid=%ld sum=%d",retval2->tid,retval2->sum);	
	}
	printf("Good Bye!\n");
	pthread_exit(NULL);
}







