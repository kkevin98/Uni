#include <iostream>
#include <typeinfo>

// To check the type of a variable initialized with auto

template <typename T>  // solution to line 21
void debug(T);

int main(){

    unsigned long long int a;  // okk
    // auto a{0llu};  // WRONG
    // auto a{new int[4]};  // WRONG

    debug(a);

    return 0;
}

//  QUESTIONS
//0) Are the previous notations correct??

// ANSWERS
// 0) NO!! NEVER {} WITH AUTO!! It may deduce strange types!! (std::initializer_listt)