#include <stdio.h>
#include <math.h>

float f(float x){
	return 2*x*x*x-4*x+1;
}

float bisection(float a, float b, float delta){
	float m = (a+b)/2;
	while(fabs(f(m))>delta && b-a>0.000000000001){
		if(f(m)*f(a) > 0){
			a = m;
		}
		else{
			b = m;
		}
		m=(a+b)/2;
	}
	return m;
}

int main(int argc, char *argv[]){
	float m = bisection(0,1,0.00001);
	printf("f(%f)=%f\n", m, f(m));
	return 0;
}
