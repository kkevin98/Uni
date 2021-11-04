#include <iostream>
#include <iomanip>
#include <utility>
#include <array>


// WRONG: arrays lives in the stack --> how can I pass the transpose??
// template <size_t rows, size_t columns>
// double* transpose(double* matrix, const size_t rows, const size_t columns);

template <size_t rows, size_t columns, typename M>
void transpose(M& matrix);

template <size_t rows, size_t columns, typename M>
void print_matrix(M& matrix);

int main(){

    constexpr size_t r{3};
    constexpr size_t c{2};
    constexpr auto N = r*c;  //why I need constexpr also here? Even if i give size_t instead of auto
    std::array<double, N> matrix{0.0, 1.1,
                                 2.2, 3.3,
                                 4.4, 5.5};
    // std::array<double, N> matrix{0.0, 1.1, 2.2,  // When you use square matrix change r and c!!
    //                              3.3, 4.4, 5.5,
    //                              6.6, 7.7, 8.8};


    std::cout << "La matrice è:\n";
    print_matrix<r, c>(matrix);

    transpose<r, c>(matrix);

    std::cout << "Mentre la sua trasposta è:\n";
    print_matrix<c, r>(matrix);

    return 0;
}


// void bcs I have to modify the original matrix
template <size_t rows, size_t columns, typename M>  // r and c in templates bcs I need dimensions defined at compile time
void transpose(M& matrix){
    constexpr auto N = rows*columns;
    std::array<double, N> temp{};
    temp = matrix;

    for(auto i{0llu}; i<rows; ++i){  // Does affect performances if I swap 22/23
        for(auto j{0llu}; j<columns; ++j){
            std::swap(matrix.at(i*columns+j), temp.at(j*rows+i));  // try with a M(3, 2) to understand
        }
    }
    matrix = temp;
    // no need to free the memory of temp bcs it is saved in the stack :)
}


template <size_t rows, size_t columns, typename M>
void print_matrix(M& matrix){
    for(auto i{0llu}; i<rows; ++i){
        for(auto j{0llu}; j<columns; ++j){
            size_t pos = i*columns+j;
            std::cout << std::setw(5) << matrix.at(pos);
        }
        std::cout << std::endl;
    }
}


// FURTHER IMPROOVEMENTS:
// 0) When the transpose passed to transpose() has not the inverse dimensions of the matrix
//    I should warning the user somehow...
// 1) Check the performances by swapping the navigation of the matrix

// QUESTIONS:
// 0) (SOLVED) Why during the definition of N inside transpose ther aren't problem??
//    In fact when you try to compile you get errors :|
// 1) Why std::arrays has to be passed by reference?? Aren't they similar to built-in arrays??
