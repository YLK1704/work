#include "head_1.h"

void menu(){
	printf("************************************\n");
	printf(" 0.exit \n");
	printf(" 1.create new file\n");
	printf(" 2.write file\n");
	printf(" 3.read  file\n");
	printf(" 4.modify file permissions\n");
	printf(" 5.view and modify file permissions\n");
	printf("************************************\n");
	printf("  please input your choice(0-5)");
}

void check_choice(){
	int choice;	
	scanf("%d",&choice);
	while(choice!=0 && choice!=1 && choice!=2 && choice!=3 
	&& choice!=4 && choice!=5){
		printf("input error!! please input again:");
		scanf("%d",&choice);
}
	if(choice==0)	exit(0);
	if(choice==1)  cre_file();
	if(choice==2)	wri_file();
	if(choice==3)	rea_file();
	if(choice==4)   mod_file_per();
	if(choice==5)   view_mod_file_per();
}


