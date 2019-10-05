#include "uhead.h"

void urand(int * a,int n){
	int i;
	srand((int)time(0));
	for(i=0;i<n;i++){
		a[i]=1+(int)(100.0*rand()/(RAND_MAX+1.0));
	}
}

int compar(const void *a,const void *b){
		int *aa=(int *)a,*bb=(int *)b;
		if(*aa>*bb)return 1;
		if(*aa==*bb)return 0;
		if(*aa<*bb)return -1;
}
void syssort(int *a,int n)
{
	qsort(a,n,sizeof(int),compar);
	printf("\n");

}


void bsort( int*base,int n)
{
  int i;int j;int temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(base[j]>base[j+1])
      {
        temp=base[j+1];
        base[j+1]=base[j];
        base[j]=temp;
      }
    }
  }
}
void cp(int* a,int* b,int n)
{
	int i;
	for(i=0;i<n;i++)
		b[i]=a[i];
}
void runtimes(void (*func)(int *a,int b),int *a,int n)
{
	clock_t start,end;
	start=clock();
	func(a,n);
	end=clock();
	printf("\ntime is %5.2f s\n",difftime(end,start));// difftime的返回值单位是秒
}

void showarray(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]=%d \n",i,a[i]);
	}

}

void showpath(void){
	char buf[240]={0};
	getcwd(buf,sizeof(buf));
	puts(buf);
}


