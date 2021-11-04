#include <stdio.h>

int power(int n, unsigned int m){
	int res = 1;
	for(int i=0; i<m; i++){
		res=res*n;
	}
	return res;
}

/* ***WRONG***
unsigned int int_root(unsigned int n, unsigned int, m){
	unsigned int i=1;
	unsigned int res=0;
	while(i<n){
		res++;
		i=power(i, res);
	}
	return res-1;
}
*/

unsigned int int_root(unsigned int n, unsigned int m){  /*n^(1/m)*/
	int i=0;
	while(power(i, m)<=n){  /*equal required, you're looking for the first wrong value of i*/
		i++;
	}
	return i-1;  /* if I found the first wrong value-->the previous one will be the right one*/
}

int main(int argc, char *argv[]){
	int b=1250;
	unsigned int e=3;
	printf("%d\n", int_root(b, e));
	return 0;
}
