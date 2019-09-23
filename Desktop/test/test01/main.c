#include"uhead.h"

int main(void)
{
	int a[N];
	struct arg t;
	urand(a,N);
	show(a,N);
	t=uoperater(a,N);
	printf("sum=%d,ave=%f\n",t.sum,t.ave);
	return 0;
}
