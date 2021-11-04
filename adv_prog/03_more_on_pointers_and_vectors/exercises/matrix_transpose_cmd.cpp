#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <vector>


// WRONG: arrays lives in the stack --> how can I pass the transpose??
// template <size_t rows, size_t columns>
// double* transpose(double* matrix, const size_t rows, const size_t columns);

template <typename M>
void transpose(M& matrix, const size_t& rows, const size_t& columns);

template <typename M>
void print_matrix(const M& matrix, const size_t& rows, const size_t& columns);

int main(int argc, char* argv[]){

    // reading rows and columns from commandline
    auto r = std::stoull(argv[1]);
    auto c = std::stoull(argv[2]);
    auto N = r*c;

    // defining and filling the matrix with (double)
    std::vector<double> matrix(N);
    for(std::size_t i{0}; i<N; ++i){
        matrix[i] = static_cast<double>(i);
    }

    std::cout << "La matrice è:\n";
    print_matrix(matrix, r, c);

    transpose(matrix, r, c);

    std::cout << "Mentre la sua trasposta è:\n";
    print_matrix(matrix, c, r);

    return 0;
}


// void bcs I have to modify the original matrix
template <typename M>  // r and c in templates bcs I need dimensions defined at compile time
void transpose(M& matrix, const size_t& rows, const size_t& columns){
    auto N = rows*columns;
    std::vector<double> temp(N);
    temp = matrix;

    for(auto i{0llu}; i<rows; ++i){  // Does affect performances if I swap 22/23
        for(auto j{0llu}; j<columns; ++j){
            std::swap(matrix.at(i*columns+j), temp.at(j*rows+i));  // try with a M(3, 2) to understand
        }
    }
    matrix = temp;
    // std::vector are free their memory automatically?? Where are they saved??
}


template <typename M>
void print_matrix(const M& matrix, const size_t& rows, const size_t& columns){
    for(auto i{0llu}; i<rows; ++i){
        for(auto j{0llu}; j<columns; ++j){
            size_t pos = i*columns+j;
            std::cout << std::setw(5) << matrix.at(pos);
        }
        std::cout << std::endl;
    }
}

// QUESTIONS:
// 0) std::vector are free their memory automatically?? Where are they saved??
//    Should I delete their memory?? 