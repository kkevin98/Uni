#include <stdio.h>

/*
unsigned int fibonacci(unsigned int n){
	if(n==0||n==1){
		return 1;
	}
	else{
		return fibonacci(n-2)+fibonacci(n-1);
	}
}
*/

unsigned int fibonacci(unsigned int n){
	unsigned int fib, fib_p=1, fib_p2=1;
	for(int i=0; i<n-1; i++){
		fib=fib_p+fib_p2;
		fib_p2=fib_p;
		fib_p=fib;
	}
	return fib;
}


int main(int argc, char *argv[]){
	unsigned int test=8;
	printf("Fibonacci di %d è: %d\n", test, fibonacci(8));
	return 0;
}
