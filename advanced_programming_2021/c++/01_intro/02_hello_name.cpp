#include <iostream>
#include <string>

int main() {
  std::cout << "Insert your name and age:\n";
  std::string name;
  unsigned int age;
  std::cin >> name >> age;  //I read from cin and I put what I've found in name
  std::cout << "Hello, " << name << " [" << age << "]\n";
  return 0;
}

//OSS: Se provo con "22 Kevin 22", da dove viene lo 0?? Perché non ci sono controlli e non gestisco la error flag di std::cin --> strange thing happens
