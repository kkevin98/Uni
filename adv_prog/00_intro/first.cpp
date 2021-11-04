#include <iostream>

int main(){
	std::cout << "Hello, World!!" << std::endl;
	// std::cout --> a variable called cout that can be found inside the std
	// << --> an operator that stands for "put to"
	// << std::endl --> to put a newline at the end of the output
	//		     this is the same as /n
	//		     but in practice is smthg more than "/n" is prefered when you've finished to write in the output
	
	std::cout << "Hello, World!!\n"
			<< "con un'altra riga" << std::endl;
	
	return 0;
}
