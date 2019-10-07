#include"uhead.h"

int main(void)
{
	int a[NUM];
	int b[NUM]; 
	int h,h2;
	struct arg t;
	urand(a,NUM);
	h=writedate(a,NUM,"array.txt");
	printf("before sort!");
	showarray(a,NUM);
	
	cp(a,b,NUM);

	printf("after bsort!\n");
	bsort(a,NUM);
	showarray(a,NUM);
	runtimes(bsort,a,NUM);
	h=writedate(a,NUM,"srot.txt");
	printf("%d",h);

	printf("after sysort!\n");
	syssort(b,NUM);
	showarray(b,NUM);
	runtimes(syssort,b,NUM);
	h2=writedate(b,NUM,"srot2.txt");
	printf("%d",h2);

	t=uoperater(a,NUM);
	printf("sum=%d,ave=%f\n",t.sum,t.ave);
	showpath();
	return 0;
}
