#include"uhead.h"

int main(void)
{
	int a[NUM];
	int h;
	struct arg t;
	urand(a,NUM);
	h=writedate(a,NUM,"array.txt");
	showarray(a,NUM);
	t=uoperater(a,NUM);
	printf("sum=%d,ave=%f\n",t.sum,t.ave);
	showpath();
	h=writedate(a,NUM,"srot.txt");
	printf("%d",h);
	return 0;
}
