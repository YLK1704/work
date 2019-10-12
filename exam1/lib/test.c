#include "lib.h"

int main()
{
	//int a[10] = {324,8,-9,5,0,3454,234,-987,100000,12};
	int a[10];
	urand(a,10);
	printf("max=%d",max(a,10));
	printf("sum=%d",sum(a,10));
	return 0;
}
