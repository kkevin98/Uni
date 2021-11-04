#include <iostream>

template <typename T>  // T is the name of a type and survive untile the end of the scope of the f.
T dwim(const T a, const T b);

int main() {
  int a{5}, b{7};
  double c{3.332}, d{7.7};
  float e{23.4}, f{3.34e2};
  char g{'0'}, h{'6'};

  std::cout << dwim<int>(a, b) << '\n'  // here the compiler is producing 4 different dwim functions
            << dwim(c, d) << '\n'       //  produced by a single template!!
            << dwim(e, f) << '\n'       // if you try to insert <string> --> compiler error
            << dwim(g, h) << std::endl;
  return 0;
}

template <typename T>
T dwim(const T a, const T b) {
  return a + b;
}

// line 12: how to call a template function. Use <type> to define what has to be placed instead T
//          but if the type can be deduced from the arguments <> is not needed    

//OSS: for different type arguments
// template <typename T, template S>  //defnition
// T dwim(const T a, const S b);
// dwim<int, int>(a, b) //calling or without <> it he type can be inferred

//OSS: to decide the type of the return (it cast the return type) (you put for first the template that can not be deduced from the arguments)
// template <typename S, template T>  //defnition
// S dwim(const T a, const T b);  // argument are deduced, return type is specified by the user
