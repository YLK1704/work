#include"my.h"
int count=0;
int main(){
	int fd[2];
	int fd2[2];
	pid_t p1,p2,p3;
	char buff[10];
	int sum;int tem;
	pipe(fd);
	pipe(fd2);		
	p1=fork();
	if(p1<0){
		perror("fork1 failed.\n");
		return -1;
	}
	else if(p1==0){
		close(fd[0]);
		for(int i=0;i<65536;i++){
			sprintf(buff,"%d",i);	
			write(fd[1],&buff,sizeof(buff));
			
		}
		//printf("child1 write pipe1-2 0-65535 \n");
		//printf("child1 ppid=%d  pid=%d\n",getppid(),getpid());
		close(fd[1]);
		exit(0);
	}
	else{
		printf("parent fork second time.\n");
		p2=fork();
		if(p2<0){
			perror("fork2 failed.\n");
			return -1;
		}
		else if(p2==0){
			close(fd[1]);
			close(fd2[0]);
			for(int i=0;i<65536;i++){	
				read(fd[0],buff,sizeof(buff));
				printf("%s ",buff);	
				write(fd2[1],&buff,sizeof(buff));			
				
			}
			close(fd2[1]);
			close(fd[0]);
			printf("child2 ppid=%d  pid=%d\n",getppid(),getpid());
			exit(0);
		}
		else{
			p3=fork();
			if(p3<0){
				perror("fork1 failed.\n");
				return -1;
			}
			else if(p3==0){
				close(fd2[1]);
				for(int i=0;i<65536;i++){	
					read(fd2[0],buff,sizeof(buff));
					tem=atoi(buff);
					sum+=tem;
				
				}
				sleep(1);
				printf("read form pipe2,and the sum is %d\n",sum);
				close(fd2[0]);
				printf("child3 ppid=%d  pid=%d\n",getppid(),getpid());
				exit(0);
			}
			else{
				printf("parent waiting!!\n");
				wait(NULL);
				wait(NULL);wait(NULL);
				printf("parent  pid=%d\n",getpid());
	
			}
		}
		
	}

	return 0;
}