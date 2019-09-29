#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){
	int fd;
	if((fd=open("lseek",O_RDWR |O_APPEND))<0)
	{
		printf("open fail!!");
		exit(-1);
	}
	int offt;
	if((offt=lseek(fd,0,SEEK_END))==-1){
		printf("lseek error!");
		exit(-1);
	}
	int wb;
	if((wb=write(fd,"test\n",5))<0){
		printf("write error!");
		exit(-1);
	}
	int rb;
	char *rd;
	if((rb=read(fd,rd,wb))<0){
		printf("read error!");
		exit(-1);
	}
	if(write(STDOUT_FILENO,rd,rb)!=rb){
		printf("output error!");
		exit(-1);
	}

	exit(0);
}



