#include <iostream>

// To see how array are initialized

template <typename T>
void print_array(const T* array, const size_t size);

int main(){
    std::size_t upper_bound;  //realy have sense??
    std::cout << "Insert number:\n";
    std::cin >> upper_bound;

    // Use dynamic arrays to choose the upper bound
    auto selector_array = new bool[upper_bound-1]{};  //initialized to false
    auto numbers_array = new unsigned int[upper_bound-1]{};  // initialized to 0

    print_array(selector_array, upper_bound-1);
    print_array(numbers_array, upper_bound-1);

    return 0;
}


template <typename T>
void print_array(const T* const array, const size_t size){
    for(auto i = 0llu; i<size; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// QUESTIONS
// 0) While doing array[i] inside print_array, I'm not mooving the pointer??
//    So that the compiler should complain about the constant pointer in the argument
//    You're not mooving the pointer (a[i] == *(a+i))
// 1) Why can i define the length of the array in runtime from the std::cin??
//    Bcs the size of bult-in dynamic arrays can be specified in runtime
//    OSS: doing int a[n] is wrong in C++, but correct in C and the compiler does not
//         warning about that!!!

// FURTHER IMPROOVEMENTS
// 1) timing the execution and compare with prime_numbers (???)