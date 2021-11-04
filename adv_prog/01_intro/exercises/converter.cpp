#include <iostream>
#include <string>


double inch2meter(double inch);
double yard2meter(double yard);
double feat2meter(double feat);


// suppongo che l'utente sia bravo e scriva quello che mi aspetto
int main(){

	int value;
	std::string measure;
	std::cout << "Inserisci \"valore misura\":\n";

	std::cin >> value;
	std::cin >> measure;

	if(measure == "yard"){
		std::cout << yard2meter(value) << "m" << "\n";
	}
	else if(measure == "inch"){
		std::cout << inch2meter(value) << "m" << "\n";
	}
	else if(measure == "feat"){
		std::cout << feat2meter(value) << "m" << "\n";
	}
	else{
		std::cout << "Invalid input\n";
	}
	return 0;
}

double inch2meter(double inch){
    return inch/39.37;
}

double yard2meter(double yard){
    return yard/1.094;
}

double feat2meter(double feat){
    return feat/3.281;
}