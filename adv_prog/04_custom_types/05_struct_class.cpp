#include <array>
#include <iostream>
#include <vector>

struct Point_s {
// private:  // to make members of point private, but gentlement agreement says (do not change 
             // visibility of stucts left them public)
  double x;
  double y;
  void print();
};  // note ; at the end

void Point_s::print() {
  std::cout << "Structure. x = " << x << "; y = " << y << std::endl;
//   std::cout << "Structure. x = " << this->x << "; y = " << this->y << std::endl;  // is the same of the line above
}

class Point_c {
// the order of x, y, print is not important, print can access also member defined after it
  double x;
  double y;

 public:
  void print() {
    std::cout << "Class. x = " << x << "; y = " << y << std::endl;
  }  // note no ; at the end
};   // note ; at the end

int main() {
  Point_s ps;
  ps.x = 9.9;
  ps.y = 3. / 7;

  ps.print();

  Point_c pc;
  // pc.x =7.6; // error
  pc.print();  // I can access private data through public functions

  Point_s* p = &ps;
  p->x = 0.0;
  p->print();

  auto& pr = ps;
  ++pr.x;
  pr.print();

  Point_s array_of_structs[8];  // built-in array
  array_of_structs[0].x = 1;
  array_of_structs[0].y = 2;

  std::array<Point_s, 5> as;
  as[3].x = 3;

  std::vector<Point_s> vs;
  vs.push_back(ps);
  vs[0].x = 999;
  ps.x = 11;
  ps.print();
  vs[0].print();

  return 0;
}