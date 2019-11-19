#include"my.h"
int main(){
	pid_t pid;
	int k;
	pid=fork();
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid==0){
		printf("child %d :running!\n",getpid());
	}
	

}
