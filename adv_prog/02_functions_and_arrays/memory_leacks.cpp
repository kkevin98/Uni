#include <iostream>
#include <typeinfo>

// To check the type of a variable initialized with auto

int main(){
    std::size_t upper_bound;  //realy have sense??
    std::cout << "Insert number:\n";
    std::cin >> upper_bound;

    // Use dynamic arrays to choose the upper bound
    auto da{new int[upper_bound]};

    // delete[] da; // IF NOT --> MEMORY LEACK
    return 0;
}