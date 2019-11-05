#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
char * arg[]={"./test02","123","456"};
int main(){
	int ret;
	printf("cller1:pid=%d,ppid=%d\n",getpid(),getppid());
	execv("/home/ub/linuxprograme/week9/code/test02",arg);
	printf("after calling\n");
	sleep(1);
	return 0;
}
