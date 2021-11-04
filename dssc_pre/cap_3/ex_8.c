#include <stdio.h>

/* Do NOT work*/

int main(int argc, char *argv[]){
	int a=1;
	while(a<2*a){
		a=2*a;
	}
	printf("The max value for int is: %d\n", a+(a-1));
	
	long int b=1;
	while(b<2*b){
		b=2*b;
	}
	printf("The max value for long int is: %ld\n", b+(b-1));
	
	long long int i=1;
	while(i<i+1){
		i=2*i;
	}
	printf("The max value for long long int is: %lld\n", i+(i-1));
}
