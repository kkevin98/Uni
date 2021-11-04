#include <iostream>

void surprise(double a[], const std::size_t n) {  // is it a problem to define it const double a[]??
  for (auto i = 0llu; i < n; ++i) {  // auto better than int bcs otherwise you're comparing 
    a[i] = 77;                       // unsinged value (n) with signed (i) --> compiler error
  }
}

int main() {
  int ai[4];  // ai[n] not valid bcs n MUST be known at compiler time, but the compiler
              // does not complain bcs in it is a valid syntax in C
  float af[9];
  ai[0] = 9;    // first element
  af[8] = 3.3;  // last element
  ai[88] = 7;   // undefined behavior, no range checking

  for (std::size_t k{0}; k < 4; ++k)
    std::cout << "ai[" << k << "] = " << ai[k] << '\n';

  std::cout << "\n-------------------------------\n\n";

  for (std::size_t k{0}; k < 9; ++k)
    std::cout << "af[" << k << "] = " << af[k] << '\n';

  std::cout << "\n how is an array in memory?\n\n";

  for (std::size_t k{0}; k < 9; ++k)
    std::cout << "&af[" << k << "] = " << &af[k] << '\n';

  std::cout << "\n-------------------------------\n\n";

  double ad[7]{1.1, 2.2, 3.3};  // the rest is set to 0

  *ad = 9.9;  // an array is implicitly converted to
              // a pointer to its first element;
  for (std::size_t k{0}; k < 7; ++k)
    std::cout << ad[k] << std::endl;

  // double ad2[2] {1,2,3,4}; // error (obvious)

  surprise(ad, 7);
  std::cout << "after surprise()" << std::endl;
  for (std::size_t k{0}; k < 7; ++k)
    std::cout << ad[k] << std::endl;

  return 0;
}
