#include"head_1.h"

void cre_file(){
	FILE * fd;
	char filename[20];
	printf("please input new file name:");
	scanf("%s",filename);
	if((fd=fopen(filename,"w+"))==NULL){
		printf("create file %s failure\n",filename);
	}
	else{
		printf("create file %s success\n",filename);
	}
	fclose(fd);
}

void wri_file(){
	FILE * fd;
	char  buff[SIZE];
	char filename[20];
	printf("please input the file you want to write:");
	scanf("%s",filename); 
	if((fd=fopen(filename,"a+"))==NULL){
		printf("open file %s failure",filename);
		exit(1);
	}
	printf("please input the content:");
	scanf("%s",buff);
	fwrite(buff,SIZE,1,fd);
	fclose(fd);
}
void rea_file(){
	FILE * fd;
	char  buff[SIZE];
	long length=0;
	char filename[20];
	printf("please input the file you want to read:");
	scanf("%s",filename); 
	if((fd=fopen(filename,"r"))==NULL){
		printf("open file %s failure",filename);
		exit(1);
	}
	fseek(fd,0L,SEEK_END);
	length=ftell(fd);
	fseek(fd,0L,SEEK_SET);
	while(!feof(fd)){
		if(length<=SIZE){
			fread(buff,length,1,fd);
			printf("%s\n",buff);
		}else{
			fread(buff,SIZE,1,fd);
			printf("%s\n",buff);
			length=length-SIZE;
		}
		memset(buff,0,SIZE);
	}
	fclose(fd);
}


