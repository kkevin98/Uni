/* Hanoi game*/
#include <stdio.h>

void hanoi(const char src_rod, const char tmp_rod, const char dst_rod, const unsigned int n){
	if(n==0){
		return;
	}
	hanoi(src_rod, dst_rod, tmp_rod, n-1);
	printf("Move disk #%d from rod #%d to rod #%d\n", n, src_rod, dst_rod);
	hanoi(tmp_rod, src_rod, dst_rod, n-1);
}

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Syntax error, the correct syntax is: %s <tower height>\n", argv[0]);
		return 1;
	}
	unsigned int height;
	sscanf(argv[1], "%d", &height);
	hanoi(1,2,3,height);
}
