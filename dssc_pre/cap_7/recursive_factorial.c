/* Recursive factorial */
#include <stdio.h>

unsigned int rec_fact(unsigned int n){
	if(n==0){
		return 1;
	}
	return n*rec_fact(n-1);
}

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Syntax error, the correct syntax is: %s <numero>\n", argv[0]);
		return 1;
	}
	unsigned int number;
	sscanf(argv[1], "%d", &number);
	printf("%d! = %d\n", number, rec_fact(number));
}
