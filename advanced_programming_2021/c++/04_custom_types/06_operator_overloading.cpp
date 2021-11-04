#include <array>
#include <iostream>
#include <vector>

struct Point_s {
  double x;
  double y;
};  // note ; at the end

// returns std::ostream&, to support the chain calling of operator (e.g. std::cout << x << y) 
std::ostream& operator<<(std::ostream& os, const Point_s& p) {  //Now we can print Point_s
  os << "Struct. x = " << p.x << "; y = " << p.y << std::endl;
  return os;
}

class Point_c {
  double x;  // defined PRIVATE by default
  double y;

// if you remove friend --> compile error (about wrong number of operator passed to the operator)
// Must be friend otherwise you can not access the private members of the class
  friend std::ostream& operator<<(std::ostream& os, const Point_c& p) {  
    os << "Class. x = " << p.x << "; y = " << p.y << std::endl;
    return os;
  }

};  // note ; at the end

int main() {
  Point_s ps;
  ps.x = 9.9;
  ps.y = 3. / 7;

  std::cout << ps;

  Point_c pc;
  // pc.x =7.6; // error
  std::cout << pc;

  Point_s* p = &ps;
  p->x = 0.0;
  std::cout << *p;  // operator overloading does not work with pointers
  // std::cout << p;  // does not work (see above line)

  return 0;
}
