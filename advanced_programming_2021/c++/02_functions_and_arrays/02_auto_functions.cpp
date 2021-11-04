#include <iostream>

auto factorial(unsigned int n) {
  unsigned int ret{1};
  while (n > 1) {
    ret *= n;
    --n;

    // or "simply"
    // ret *= n--;
  }
  return ret;
}

int main() {
  unsigned int f5{factorial(5)};  // a problem if you change line 4 in std::size_t (bigger than unsigned int) (narrowing effect)

  auto f6 = factorial(6);  // not problem if I change the type of ret

  std::cout << "factorial of 5 is " << f5 << '\n'
            << "factorial of 6 is " << f6 << std::endl;

  // errors
  // factorial(); // too few args
  // factorial(3,4,5,5); // too many args
  // factorial("byobu"); // wrong type
  return 0;
}
