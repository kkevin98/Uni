#include <chrono>
#include <iostream>

// Smaller than 100 --> I can use short (8bits) --> an array of 100 short consume 100bytes -->
// --> it can rest in stack --> static arrray (if I know the number of prime numbers smaller than 100)
// Not a great damage if I allocate a 100bytes --> static array

bool is_prime(const std::size_t n);

template <typename T>
void print_array(const T* const array, const size_t size);

template <typename T, typename S>
void array_copy_content(T* const from_array, T* const to_array, const S smaller_size);


int main(){

    {  // other dynamic implementation
        std::size_t upper_bound;
        std::cout << "How many prime numbers??\n";
        std::cin >> upper_bound;

        auto t0 = std::chrono::high_resolution_clock::now();  // TIC

        // population of the array (dynamic)
        int size{1};
        unsigned int* array_dyn{new unsigned int[size]};
        std::size_t pos{0};
        array_dyn[pos] = 2;
        for(std::size_t i{3}; i<upper_bound; ++i){
            if(is_prime(i)){
                auto temp = array_dyn;                          // save actual array
                array_dyn = new unsigned int[++size];           // create a new memory loc. for the array
                array_copy_content(temp, array_dyn, size-1);    // copy the old values in the new memory locatio of arrray
                array_dyn[++pos] = static_cast<unsigned int>(i);  // add the new prime number found
                delete[] temp;                                  // free memory occupied by the old array
            }
        }

        // print the results
        std::cout << "(from dynamic 2) The prime numbers are:\n";
        print_array(array_dyn, pos);

        // free the memory
        delete[] array_dyn;

        auto t1 = std::chrono::high_resolution_clock::now();  // TAC
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
        std::cout << "Dynamic array 2 took: [" << elapsed.count() << " us]" << std::endl;


    }

    {   
        // using unsigned int for dynamic case, bcs users may insert an high number of prime numb
        // that short is not able to manage
        std::size_t upper_bound;
        std::cout << "How many prime numbers??\n";
        std::cin >> upper_bound;

        auto t0 = std::chrono::high_resolution_clock::now();  // TIC

        // population of the array (dynamic)
        unsigned int* const array_dyn{new unsigned int[upper_bound]};
        std::size_t pos{0};
        array_dyn[pos] = 2;
        for(std::size_t i{3}; i<upper_bound; ++i){
            if(is_prime(i)){
                array_dyn[++pos] = static_cast<unsigned int>(i);
            }
        }

        // print the results
        std::cout << "(from dynamic 1) The prime numbers are:\n";
        print_array(array_dyn, pos);

        // free the memory
        delete[] array_dyn;

        auto t1 = std::chrono::high_resolution_clock::now();  // TAC
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
        std::cout << "Dynamic array 1 took: [" << elapsed.count() << " us]" << std::endl;
    }

    {   

        auto t0 = std::chrono::high_resolution_clock::now();  // TIC

        // population of the array (static)
        unsigned int array_sttc[100]{};
        std::size_t pos{0};
        array_sttc[0] = 2;
        for(std::size_t i{3}; i<100; ++i){
            if(is_prime(i)){
                array_sttc[++pos] = static_cast<unsigned int>(i);
            }
        }

        // print the results
        std::cout << "(from static) The prime numbers are:\n";
        print_array(array_sttc, pos);

        auto t1 = std::chrono::high_resolution_clock::now();  // TAC
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
        std::cout << "Dynamic array took: [" << elapsed.count() << " us]" << std::endl;
    }
    return 0;
}

bool is_prime(const std::size_t n){
    unsigned int remainder;
    for(unsigned int divider{2}; divider<n; divider++){
        remainder = n%divider;  // il resto
        if(remainder){
            continue;
        }
        else{
            return false;  // resto==0 --> non è primo
        }
    }
    return true;
}

template <typename T>
void print_array(const T* const array, const size_t size){
    for(auto i = 0llu; i<size; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T, typename S>
void array_copy_content(T* const from_array, T* const to_array, const S smaller_size){
    for(std::size_t i{0}; i<smaller_size;  ++i){
        to_array[i] = from_array[i];
    }
}

//OSS: FURTHER IMPROOVEMENTS
// 1 --> Add a populate_array function to free the main function
// 2 [DONE] --> Create a version of the same program with static array
// 3 [DONE]--> Resize the elements while you're adding the prime numbers

// RESULTS:
// Resize a dynamic array is very heavy and slow;
// Use a prefixed size dynamic array is slightly better, but not too much
// Static array is much faster :)