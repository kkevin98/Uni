#include <iostream>

int main(){

	// bolean
	bool t{1};  // if 54 compiler complain
	std::cout<<t<<std::endl;
	
	//strings
	std::string a{"Ciao"};
	std::string b{"Mondo"};
	std::cout << a+b << std::endl;  // + is concatenation for strings
	
	// bit operations
	int x{16};
	x >>= 22;
	std::cout << x << std::endl;
	
	// if test
	if(-45){
		std::cout << "Ciao" << std::endl;
	}

	return 0;
}

// OSS
// M_PI is a constant for pi (needs math library)	
// void(unused variable) to avoid warnings :)
