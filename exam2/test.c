#include "/home/ub/exam1/lib/lib.h"

int main()
{
	int a[10];
	urand(a,10);
	printf("max=%d",max(a,10));
	printf("sum=%d",sum(a,10));
	return 0;
}