#include <cmath>
#include <iostream>

template <typename T>  // solution to line 21
void debug(T);

int main() {
  auto b = true;          // a bool
  auto ch = 'x';          // a char
  auto i = 123;           // an int
  auto d = 1.2;           // a double
  auto z = std::sqrt(d);  // z has the type of whatever sqrt(d) returns
  auto ui = 0u;           // unsigned int
  auto llui = 0llu;       // long long unsigned int

  auto& j = i;  // int& --> also references "autodetect" their type

  for (auto i = 0; i < 7; ++i)
    std::cout << i << std::endl;

  auto pb = &b;  // guess what.. How can I know? Produce a compiler error
  // debug(pb);  // solution to line 21

  auto s = "hello";  // watch out! It is not a string it is an array of char!!
                     // use the debug function to know it!
  
  // debug(s);

  return 0;
}
