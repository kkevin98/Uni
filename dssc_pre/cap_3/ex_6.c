#include <stdio.h>

int main(int argc, char *argv[]){
	printf("%d\n", 1);
	int c=1;
	int i=2;
	while(c!=50){  /*fino a quando non li ho stampati tutti e 50*/
		int j=2;
		while(j<i){  /*comincio a testare il numero*/
			if(i%j==0){  
				i++;  /*non è primo-->passo al prox*/
				j=2;  /*riprovando a dividerlo da capo*/
			}
			else{
				j++;
			}	
		}
		printf("%d\n", i);
		i++;
		c++;
	}
	return 0;
}
