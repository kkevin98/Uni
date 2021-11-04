#include <iostream>

// Print the nullptr

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {

    int* p = nullptr;

    // std::cout << *p << std::endl;  // error
    std::cout << p << std::endl;

    return 0;
}