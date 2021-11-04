#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);  // not match the signature  in line 68

int main() {
  int a{8};
  int* pi{&a};

  char** ppc;

  int* ap[7];

  void* pv{pi};  //it can point to whatever type
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why? Bcs it does not know the size of a single jump when iterating (it does not know the type)
  int* pi2{static_cast<int*>(pv)};  // in c: (int *)pv --> it is slower in c++ (but admitted)
  //OSS: void* is rarely used in c++ bcs we have templates :)
  //     doing as C, a casting evaluated at runntime is always performed

  pv = ppc;
  pv = ap;
  pv = pi;

  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;  // error, why? ap is name of a static array (sort of const pointer)
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr. please don't do it

  // pi = NULL; // please don't do it

  double* da{new double[5]{}};
  delete[] da;  // dangling pointer (where they might be origin)
  da = nullptr;  // best practice to avoid dangling pointer
  
  // std::cout << *da  // not correct
  // std::cout << da  // correct

  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi)  //same if as 45 bcs if pi has a value it will be positive and considered true
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  if (!pi)  // same as line 53
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[]
  char word[]{"Hello"};  // better than line 60
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};  // corrected, but bit confusing
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2) --> must use strcmp to compare strings
    std::cout << "same\n";
  else
    std::cout << "different\n";

  int (*fp)(const char*);  // pointer to a function --> () are mandatory
  fp = func1;  // correct

  fp("hello");

  fp = &func2;  // correct, as line 71 (you can use or not &)
  fp("world");

  // fp = func3; // error: wrong signature
  auto xx = func3;

  xx("auto");

  decltype(&func3) x = func3;  // decltype can be used in templates (similar to line 79)
  x("decltype");
  // the difference is that you can use x in template function

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;  // This return 1, is putted just to return something
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
