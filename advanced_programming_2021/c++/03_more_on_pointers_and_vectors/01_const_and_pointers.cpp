#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc{&a};  //const value inside the box of the pointer
  // *pc = 7; 	// error
  a = 15;  // I can obviously change a (WOW, not foregone!!)

  int* const cp{&a};  //const pointer 
  a = b;
  *cp = 33;
  // cp = &b;   // error

  const int* const cpc{&a};  //mix of line 10 and 14

  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}

// pointer arithmetics (l is the length of the array)
template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end{a + l};  // end is the sentinel 
  for (; a != end; ++a)
    std::cout << *a << std::endl;
}
//OSS: the a in the functino is not the aa pointer that I pass in line 26 


