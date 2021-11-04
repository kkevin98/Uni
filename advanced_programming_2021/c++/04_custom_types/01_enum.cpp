#include <iostream>

enum color { red, yellow, green };
// enum color{red=0, yellow=1, green=2}; // equivalent
// enum led { red, blue, green}; // still logically okk, but does not compile
//enum led { red, green, blue}; // where problem arise... which value should I read when I see green??

void dwim(const color c) {
  switch (c) {
    case red:
      std::cout << "option 1: red\n";
      break;  // to avoid to check the other cases
    case yellow:
      std::cout << "option 2: yellow\n";
      break;
    case green:
      std::cout << "option 3: green\n";
      break;
    default:
      std::cout << "unknown option\n";  // should I exit the program?
      break;
  }
}

int main() {
  color opt{red};
  // opt = 3; // cannot assign int to enum
  int a{opt};  // but they implicitly convert to integers this is allowed

  dwim(opt);

  dwim(yellow);

  // dwim(2); // error
  dwim(color(2));  // works but why you may want to write this?

  dwim(color(6));  // ???

  return 0;
}
