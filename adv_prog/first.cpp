#include <iostream>
// iostream --> is a library, but we are including it!!
// header --> to make know to the compiler the objects type
// library --> tell where the objects type are implemented

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

//OSS: printf --> is a function, and is up to you to pass the correct arguments
//	   cout --> is not a function is an operator
