#include"my.h"
int main(){
	pid_t p1,p2,p3;
	p1=fork();
	p2=fork();
	p3=fork();
	if(p1==0){
		printf("1");
	}
else if(p2==0){
		printf("2");
	}

else if(p3==0){
		printf("3");
	}


	return 0;
}
