#include "uhead.h"

int writedate(int*a,int n){
	FILE * to_file;	
	if((to_file=fopen("rowdata.txt","wb"))==NULL){
		printf("Open Error\n");
		return 0;
	}
	fwrite(n,1,to_file,a);
	return 1;
}
