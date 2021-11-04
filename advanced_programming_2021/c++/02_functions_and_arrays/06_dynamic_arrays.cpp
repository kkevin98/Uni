#include <iostream>

int main() {
  std::cout << "Please insert array lenght: ";
  std::size_t n;
  std::cin >> n;
  int* da{new int[n]};  // allocated on the HEAP, or free-store
  
  // auto da = new int[n];  // also a valid syntax same as "malloc" (unitialized values in the array)
  // auto da = new int[n]{};  // same as "calloc" (fill the array with zeros) 

  for (std::size_t i{0}; i < n; ++i)
    da[i] = i * 10;

  for (std::size_t i{0}; i < n; ++i)
    std::cout << "da[" << i << "] = " << da[i] << std::endl;

  delete[] da;
  return 0;
}
