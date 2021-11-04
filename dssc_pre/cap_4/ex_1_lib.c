#include <stdio.h>
#include "firstlib.h"  /*We use " if the lib are not contained in the standard location*/

int main(int argc, char *argv[]){
	int b=-3;
	unsigned int e=2;
	printf("%d\n", power(b, e));
	return 0;
}
