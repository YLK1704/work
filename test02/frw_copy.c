#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#define SIZE 1024

int main(){
	FILE *fdsrc;
	FILE *fddes;
	long nbytes=0;
	char buf[SIZE],des[20];
	printf("please input file name:");
	scanf("%s",des);
	fdsrc = fopen("./shead.h","r+");
	if(fdsrc==NULL){
		exit(1);
	}
	fddes=fopen(des,"W+");
	if(fddes==NULL){
		exit(1);
	}
	fseek(fdsrc,0L,SEEK_END);
	nbytes=ftell(fdsrc);
	fseek(fdsrc,0L,SEEK_SET);
	while(!feof(fdsrc)){
		fread(buf,1,SIZE,fdsrc);
		if(20>=nbytes){
			fwrite(buf,SIZE,1,fddes);
		}else{
			fwrite(buf,SIZE,1,fddes);
			nbytes=nbytes-SIZE;
		}
		memset(buf,0,SIZE);
	}
	fclose(fdsrc);
	fclose(fddes);
	printf("copy file to %s success\n",des);		
	exit(0);
}
