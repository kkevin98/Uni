#include <stdio.h>

int main(int argc, char *argv[]){
	int test = 12345679;
	for(int i=2; i<test; i++){
		if(!(test%i)){
			printf("Not prime number\n");
			return 0;
		}
	}
	printf("Not a prime number\n");
	return 0;
}
