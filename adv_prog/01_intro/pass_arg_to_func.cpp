#include <iostream>

// Different ways to pass args to funcion

// I'm not defining the body of the func to force an error to deduce the type of the Ts
//OSS: f<int>(int): <int> --> first T, (int) --> second T

// Passing by value
// template <typename T>  // first T
// void f(T a);  // second T

// Passing by reference
template <typename T>  // first T
void f(T& a);  // second T

// Passing by constant reference
// template <typename T>  // first T
// void f(const T& a);  // second T

constexpr auto func();
constexpr auto func(){
    return 45;
}

int main(){
    int i = 0;
    const int ci = 0;
    int& ri = i;

    // f(i);
    // fist T --> int, second T --> int (PASSING BY VALUE)
    // fist T --> int, second T --> int& (PASSING BY REFERENCE)
    // fist T --> int, second T --> const int& (PASSING BY CONST REFERENCE)


    f(ci);
    // fist T --> int, second T --> int (PASSING BY VALUE)
    // fist T --> int, second T --> int& (PASSING BY REFERENCE)  (Why loose the constness??)
    // fist T --> int, second T --> const int& (PASSING BY CONST REFERENCE) (Why loose the first constness??)


    // f(ri);
    // fist T --> int, second T --> int (PASSING BY VALUE) (oss: if you want to modify the value of the passed value you need a reference as arg of the function)
    // fist T --> ........, second T --> ..... (THIS IS THE 4TH WAY TO PASS ARG TO FUNCTIONS)
    // fist T --> int, second T --> const int& (PASSING BY CONST REFERENCE)

    // both the 3 cases below (auto) are equal to PASSING BY VALUE
    auto x = i;
    // auto x = ci;
    // auto x = ri;
    f(x);

    // constexpr variables --> its value must be known at compile time
    constexpr int t = 0;
    constexpr int tf = func();  // valid iff func is evaluated at compile time 
    // t and tf --> can be passed to function through templates bcs evaluated at compile time
    // i, ci, ri can not do that!!
}

// OSS: int const& == const int&

//QUESTIONS
// 0) Not very clear the story abput the first T and the second T... does a variable
//    "pass" to both the templates and the argument of the function??
//    The first T seems to get rough info about the variable that the function has to treat
// 1) Why if I define a constexpr function after the main the compiler complains?? How the
//    const expr are implemented, it is a design choice
// 2) The loss of constness in the first T seems a design choice... (line 39 and 45).
//    Why we loose the second constness when passing by reference in line 38??

//FURTHER IMPROOVEMENTS
// 0) Timing the function func in different scenarios (surely evaluated at compile time,
//    surely evaluated in runtime, ....)