#include"my.h"
int main(){
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0){
		printf("creat pipe fail");
		return -1;
	}
	result = fork();
	if(result<0){
		perror("creat child fail");
		exit;
	}
	else if(result==0){
		close(pipe_fd[1]);
		if((r_num=read(pipe_fd[0],buf_r,100))>0){
			printf("child read from pipe %d ,the string is %s\n",r_num,buf_r);
		}
		close(pipe_fd[0]);
		exit(0);
	}
	else
	{
		close(pipe_fd[0]);
		if(write(pipe_fd[1],"the first",10)!=-1)
			printf("parent write the 'the first' !\n");
		if(write(pipe_fd[1],"the second",11)!=-1)
			printf("parent write the 'the second' !\n");
		close(pipe_fd[1]);
		waitpid(result,NULL,0);
		exit(0);
	}
}
