#include <stdio.h>

int power(int n, unsigned int m){
	int res = 1;
	for(int i=0; i<m; i++){
		res=res*n;
	}
	return res;
}

int main(int argc, char *argv[]){
	int b=-3;
	unsigned int e=2;
	printf("%d\n", power(b, e));
	return 0;
}
