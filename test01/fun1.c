#include "uhead.h"

void urand(int * a,int n){
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++){
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
	}
}

int compar(const void *a,const void *b){
	int *aa=(int*)a,*bb=(int*)b;
	if(*aa>*bb) return 1;
	if(*aa==*bb) return 0;
	if(*aa<*bb) return -1;
}

void showarray(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]=%d \n",i,a[i]);
	}
	qsort(a,n,sizeof(int),compar);
	printf("after sort: \n");
	for(i=0;i<n;i++){
		printf("a[%d]=%d \n",i,a[i]);
	}
}
void showpath(void){
	char buf[240]={0};
	getcwd(buf,sizeof(buf));
	puts(buf);
}


