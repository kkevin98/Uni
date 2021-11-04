#include <iostream>
#include <string>

// allocate and initialize the array
template <typename T>
T* allocate(const size_t size);

// print in the reverse order the elements of the passed array
template <typename T>
void print_reverse_array(const T* array, const size_t size);

int main(){

    std::size_t n;

    std::cout << "Please insert array lenght: ";
    std::cin >> n;
    std::cout << "Please insert array element(s):\n";
    auto a = allocate<int>(n);
    return 0;
}

template <typename T>
T* allocate(const size_t size){
    T* array{new T[size]};                  // allocate the memory in the heap
    for(auto i = 0llu; i<size; i++){        // fill the array
        std::cin >> array[i];
    }
    return array;
}


template <typename T>
void print_reverse_array(const T* array, const size_t size){
    for(auto i = 0llu; i<size; ++i){
        std::cout << array[size-i-1] << " ";
    }
    std::cout << std::endl;
}