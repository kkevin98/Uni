/* A library containing the power function */

int power(int n, unsigned int m){
	int res = 1;
	for(int i=0; i<m; i++){
		res=res*n;
	}
	return res;
}
