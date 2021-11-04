/* staff about the params of the program */
#include <stdio.h>

int main(int argc, char *argv[]){
	printf("The n of params passed is: %d\n", argc);
	printf("The params are:\n");
	for(int i=0; i<argc; i++){
		printf("%s\n", argv[i]);
	}
	return 0;
}
