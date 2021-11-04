#include <iostream>

// Change the pointed variable of a pointer that point to const values

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc{&a};  //const value inside the box of the pointer
  // *pc = 7; 	// error
  a = 15;  // I can obviously change a
  std::cout << *pc << std::endl;

  return 0;
}