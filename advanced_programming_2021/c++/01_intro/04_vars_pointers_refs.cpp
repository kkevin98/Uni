#include <iostream>

int main() {
  double d = 9.9;
  double& ref = d;  //-->double* x{&d};
  double* ptr = &d;
  double* ptr {nullptr}; //a pointer that is not pointing
  			  //OSS: if you try *ptr of the before definition you get segmentation 				  //fault error
  			 
  // OSS: how references works
  // double* x{&d};
  // ref --> *x  // a real comment
  // You're not able to get the pointer of x!
  
  std::cout << "value of   d: " << d << std::endl;
  std::cout << "value of ref: " << ref << std::endl;
  std::cout << "value of ptr: " << ptr << std::endl << std::endl;

  std::cout << "address of   d: " << &d << std::endl;
  std::cout << "address of ref: " << &ref << std::endl;
  std::cout << "address of ptr: " << &ptr << std::endl << std::endl;

  // the value of variable d can be changed through either ref or
  // ptr as follows
  ref = 7.7;
  std::cout << "value of   d: " << d << std::endl;

  *ptr = 5.5;
  std::cout << "value of   d: " << d << std::endl;
}

// OSS
// Refernce is a sort of "different name for the same object"
// Must be initialized when created
// NULL!=nullptr  std::nullptr_t
