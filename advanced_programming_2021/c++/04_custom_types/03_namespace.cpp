#include <iostream>

namespace choose_a_name {

  int variable;

  namespace nested {  // nested namespace (couldn't be opened again outside choose_a_name!!)

    void hello1();
    void hello2();
    void hello3();

  }  // namespace nested
}  // namespace choose_a_name

int main() {
  // variable = 42; // error
  choose_a_name::variable = 42;
  // hello1(); // error
  // choose_a_name::hello1();  // Added by me --> I'm not able to get into inner namespaces to search variables that I've not found 
  choose_a_name::nested::hello1();
  choose_a_name::nested::hello2();
  choose_a_name::nested::hello3();
  return 0;
}

void choose_a_name::nested::hello1() {
  std::cout << "hello1 from nested\n"
            << "variable is " << choose_a_name::variable << std::endl;  //variable must be accessed with the fully qualifier name, bcs we haven't opened previously its scope
}

// namespace nested{};  // Wrong!! --> Have to open choose_a_name first

namespace choose_a_name {  // reopening the previous closed namespace
  namespace nested {
    void hello2() {
      std::cout << "hello2 from nested\n"
                << "variable is " << variable << std::endl;
    }
  }  // namespace nested
}  // namespace choose_a_name

using namespace choose_a_name;  // populate the GLOBAL ENVIRONMENT  
// open a namespace, now I can use the variables of that namespace without the fully qualif. name (DISCURAGED USAGE DUE TO NAMECLASHES) You could define variables that overload the ones defined in choose_a_name

void nested::hello3() {
  std::cout << "hello3 from nested\n"
            << "variable is " << variable << std::endl;
}
