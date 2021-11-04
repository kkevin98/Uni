#include <stdio.h>

int main(int argc, char *argv[]){
	int acc;
	int temp;
	for(int i=0; i<10000; i++){
		temp = i^2;
		acc = acc + i^2;
	}
	printf("The sum is:%d\n", acc);
	return 0;
}
