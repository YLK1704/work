#include"my.h"
int main(){
	pid_t p;
	
	int fd[2];
	char buf_r[100];char buf_w[100];
	int wn,rn;
	memset(buf_r,0,sizeof(buf_r));memset(buf_w,0,sizeof(buf_w));

	if(pipe(fd)<0){
		printf("creat pipe fail");
		return -1;
	}
	p = fork();
	if(p<0){
		perror("creat child fail");
		return -1;
	}
	else if(p==0){
		close(fd[0]);
		printf("child pid =%d\n",getpid());
		sprintf(buf_w,"child is running ,pid=%d",getpid());
		if((wn=write(fd[1],buf_w,sizeof(buf_w)))<0){
			printf("write failed\n");
		}
		printf("child write to pipe %d ",wn);
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		//waitpid(p,NULL,0);
		printf("parent pid =%d\n",getpid());
		if((rn=read(fd[0],buf_r,100))<0){
			printf("read failed\n");
		}
		printf("parent read from pipe %d !\n",rn);
		printf("%s",buf_r);
		close(fd[0]);	
		exit(0);
	}
}
