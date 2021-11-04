/* array of array instead pointer to an array*/
#include <stdio.h>

int main(int argc, char *argv[]){
	char test[][];  /* not works */
	char test[30][40];  /* not works (40 strings of size 30) */
	return 0;
}
