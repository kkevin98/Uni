#include <iostream>

enum class month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

using namespace std;  // should be avoided
// using std::cout;
// using std::endl;

int main() {
    // cout << month::nov << endl;  // okk
    // month value{dec};  // still ambiguous, try to print it
    cout << static_cast<int>(month::dec) << endl;
   
    return 0;
}