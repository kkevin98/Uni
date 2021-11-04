#include <iostream>
#include <string>

int get_int();

double get_double();

int main(){

    // The other loop continue reading while I'm inserting correct values, but I want to
    // stop it at the first good input!!

    std::cout << "Dammi un intero:\n";

    int int_numb = get_int();

    std::cout << "L'intero che ho letto è:\n"
              << int_numb
              << "\n";

    std::cout << "Dammi un double:\n";

    double double_numb = get_double();

    std::cout << "Il \"reale\" che ho letto è:\n"
            << double_numb  
            << "\n";

    // Is a bad practice finish your code without calling std::endl??

    return 0;
}

int get_int(){
    int i;
    while(!(std::cin >> i)){  // stops when reach a valid input
        std::cin.clear();
        std::cin.ignore();
        // std::cout << "Per favore, inserire solo numeri\n";  // Lo stampa AD OGNI carattere non valido
    }
    return i;
}

double get_double(){
    double d;
    while(!(std::cin >> d)){  // stops when reach a valid input
        std::cin.clear();
        std::cin.ignore();
    }
    return d;
}

// QUESTIONS:
// Prova con "ciao, return, 12, ctrl+D, ctrl+D, 2.3" --> get_double fails