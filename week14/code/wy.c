#include"my.h"
int main(){
	int i;
	long t1,t2;t1=time(NULL);
	for(i=0;i<100;i++){}
	t2=time(NULL);
	printf("%d",(t2-t1));
	return 0;
}
