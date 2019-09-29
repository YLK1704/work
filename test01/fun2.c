#include "uhead.h"

struct arg uoperater(int * a,int n){
	int i;
	struct arg k;
	k.sum=0;
	k.ave=0;
	for(i=0;i<n;i++)
		k.sum=k.sum+a[i];
	k.ave=((float)k.sum)/n;
	return k;
}


