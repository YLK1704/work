#include"head_1.h"

void mod_file_per(){
	char path[50];
	char smode[20];int mode;
	int mode_u,mode_g,mode_o;
	printf("please input file path:");
	scanf("%s",path);
	printf("please input mode(octal):");
	scanf("%s",smode);
	mode=atoi(smode);
	if(mode>777||mode<0){
		printf("mode num error!\n");
		exit(0);		
	}
	mode_u=mode/100;mode_g=mode/10%10;
	mode_o=mode%10;
	mode=(mode_u*8*8)+(mode_g*8)+mode_o;
	if(chmod(path,mode)==-1)
	{
		printf("chmod error!");exit(1);
	}
}

void view_mod_file_per(){
	struct stat buf;
	char path[50];
	char choice;
	char smode[20];int mode;
	int mode_u,mode_g,mode_o;
	int i;
	printf("please input file path that you want view :");
	scanf("%s",path);
	stat(path,&buf);
	switch(buf.st_mode&S_IFMT)//file type
	{
		case S_IFREG: printf("-");break;
		case S_IFDIR: printf("d");break;
		case S_IFCHR: printf("c");break;
		case S_IFBLK: printf("b");break;
		case S_IFIFO:printf("p");break;
		case S_IFLNK:printf("l");break;
		case S_IFSOCK:printf("s");break;
	}
	for(i=8;i>=0;i--){
		if(buf.st_mode&(1<<i)){
			switch (i%3){
				case 2: printf("r"); break;
				case 1: printf("w"); break;
				case 0: printf("x"); break;
			}
		}
		else{
			printf("-");
		}			
	}
	printf("Do you want to modify(Y/N)??");
	getchar();scanf("%c",&choice);
	if(choice=='Y'||choice=='y'){
		printf("please input mode(octal):");
		scanf("%s",smode);
		mode=atoi(smode);
		if(mode>777||mode<0){
			printf("mode num error!\n");
			exit(0);		
		}
		mode_u=mode/100;mode_g=mode/10%10;
		mode_o=mode%10;
		mode=(mode_u*8*8)+(mode_g*8)+mode_o;
		if(chmod(path,mode)==-1)
		{
			printf("chmod error!");exit(1);
		}
	}
}
