#include <iostream>

enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

using namespace std;  // should be avoided

int main() {
  cout << nov << endl;  // okk
  // cout << dec << endl;  //not okk (nameclashing) --> it can be avoided with scoped_enums
  
  // to make it work you should use a static cast, bcs you have to take care about operator overloading --> static_cast<int>(dec)

  return 0;
}

// see mine 04_why_scoped to more details
