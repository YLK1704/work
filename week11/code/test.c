#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	FILE *fp;
	pid_t pid;
	int i;
	if((fp=fopen("out.dat","w+"))==NULL){
		perror("open fail!!");
		exit(-1);
	}
	
	pid=fork();
	if(pid<0){
		perror("vfork failed!\n");
		exit(-1);
	}
	else if(pid==0){
		for(i=0;i<10;i++){
			fprintf(fp,"child date: %d\n",i);
		}
		//_exit(0);
		exit(0);
	}
	else{
		for(i=0;i<10;i++){
			fprintf(fp,"parent date: %d\n",i);
		}
	}
	fclose(fp);
	return 0;
}
