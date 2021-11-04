#include <stdio.h>

int main(int argc, char *argv[]){
	int i=0;
	while(i*i*i<123456789){
		i++;
	}
	printf("The integer cube root is:%d\n", i-1);
	return 0;
}
