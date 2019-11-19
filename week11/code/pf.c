#include"my.h"
#define N 1024
int main(void){
	pid_t pid;
	char buff[N];
	int fd[2];  //pipe
	int len;
	FILE *fp;
	char *p="0123456789";
	int i;
	if(pipe(fd)==-1){
		perror("pipe");
		exit(1);
	}
	if((fp=fopen("file.txt","w+"))==NULL){
		printf("open file  failure");
		exit(1);
	}
	pid=fork();
	if(pid<0){
		perror("fork1 error");
		exit(-1);
	}
	else if(pid==0){
		close(fd[0]);  //close read
		write(fd[1],p,strlen(p));
		close(fd[1]);
		
	}
	else{
		
		if((pid=fork())<0){
			perror("fork2 error");
			exit(-1);
		}	
		else if(pid==0){
			close(fd[1]);  //close write
			len=read(fd[0],buff,sizeof(buff));
			printf("%d\n",len);
			close(fd[0]);
			fwrite(buff,len,1,fp);
			
		}
		else{
			close(fd[1]);
			close(fd[0]);
			wait(NULL);
			len=10;			//printf("%d",len);
			fseek(fp,0L,SEEK_SET);
			memset(buff,0,N);
			fread(buff,N,1,fp);
			for(i=0;i<len;i++){
				printf("%c",buff[i]);
			}
		}	
	}
	fclose(fp);
	exit(0);

}
