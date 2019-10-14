#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
int main()
{
	int a[10];
	void *handle;
	void (*f1)(),(*f2)();
	int  (*f3)(),(*f4)();
	char *error;
	handle = dlopen("/home/ub/linuxprograme/week6/code/dynamiclib/libdynamic.so" , RTLD_LAZY);
	if(!handle){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1=dlsym(handle,"urand");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2=dlsym(handle,"show");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f3=dlsym(handle,"max");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f4=dlsym(handle,"sum");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1(a,10);
	f2(a,10);
	printf("max=%d",f3(a,10));
	printf("sum=%d",f4(a,10));
	if(dlclose(handle)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	return 0;
}
