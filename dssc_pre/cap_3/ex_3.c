#include <stdio.h>

int main(int argc, char *argv[]){
	int acc;
	for(int i=0; i<10000; i++){
		acc = acc + i;
	}
	printf("The sum is:%d\n", acc);
}
