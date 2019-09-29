#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int fdsrc,fddes,nbytes;
	int flags=O_CREAT | O_TRUNC | O_WRONLY;
	int z;
	char buf[20],src[20],des[20];
	printf("please input file name:");
	scanf("%s",des);
	fdsrc = open("./shead.h",O_RDONLY);
	if(fdsrc<0){
		exit(1);
	}
	fddes=open(des,flags,0644);
	if(fddes<0){
		exit(1);
	}
	while((nbytes=read(fdsrc,buf,20))>0){
		z=write(fddes,buf,nbytes);
		if(z<0){
			printf("write wo");			
		}
	}
	close(fdsrc);
	close(fddes);
	printf("copy file to %s success\n",des);		
	exit(0);
}
