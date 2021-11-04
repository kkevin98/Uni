#include <iostream>
#include <cmath>

// give the pos of the prime numbers
void sieve_of_Eratosthenes(bool* const selector, const std::size_t size);

// print the prime numbers
template <typename T>
void selection_print(const bool* const selector, const T* const print_array, const std::size_t size);


int main(){
    std::size_t upper_bound;  //realy have sense??
    std::cout << "Insert number:\n";
    std::cin >> upper_bound;

    // Use dynamic arrays to choose the upper bound
    bool* selector_array{new bool[upper_bound-1]};
    unsigned int* numbers_array{new unsigned int[upper_bound-1]};

    //array initialization
    selector_array[0] = false;
    selector_array[1] = false;
    numbers_array[0] = 0;
    numbers_array[1] = 1;
    for(std::size_t i{2llu}; i<upper_bound; ++i){
        selector_array[i] = true;
        numbers_array[i] = i;
    }

    // selecting prime numbers
    sieve_of_Eratosthenes(selector_array, upper_bound);

    // printing the prime numbers
    selection_print(selector_array, numbers_array, upper_bound);

    // free the memory
    delete[] selector_array;
    delete[] numbers_array;

    return 0;
}

void sieve_of_Eratosthenes(bool* const selector, const std::size_t max){
    for(std::size_t i{2}; i<std::sqrt(max); ++i){
        if(selector[i]){
            std::size_t step{0};
            std::size_t pos{i*i};
            while(pos < max){
                selector[pos] = false;
                step++;
                pos = i*i + step*i;
            }
        }
    }
}

template <typename T>
void selection_print(const bool* const selector, const T* const print_array, const std::size_t size){
    for(std::size_t i{0}; i<size; ++i){
        if(selector[i]){
            std::cout << print_array[i] << " ";
        }
    }
    std::cout << std::endl;
}