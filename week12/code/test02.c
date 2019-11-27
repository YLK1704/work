#include"my.h"
int main(){
	pid_t p;
	
	int fd[2];
	//char buf_r[100];char buf_w[100];
	int wn,rn;
	//memset(buf_r,0,sizeof(buf_r));memset(buf_w,0,sizeof(buf_w));
	char buff[100];
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
		char b='a';
		close(fd[0]);
		printf("child pid =%d\n",getpid());
				
		for(int i=0;i<65537;i++){
			printf("child write %d times.\n",i);
			write(fd[1],&b,1);
		}
		printf("child write ok.\n");
		close(fd[1]);
		exit(0);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		//waitpid(p,NULL,0);
		printf("parent pid =%d\n",getpid());
		for(int i=0;i<65537;i++){
			
			read(fd[0],buff,1);
			printf("%d:parent read from pipe :%s\n",i,buff);
		}

		close(fd[0]);	
		exit(0);
	}
}
