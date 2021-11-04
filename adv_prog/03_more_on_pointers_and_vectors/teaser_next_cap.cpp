#include <iostream>
#include <string>
#include <vector>

template <typename T>
void type_finder(T);

int main(){
    std::vector<bool> x{true, true, false};
    auto boo = x[0];
    type_finder(boo);
    return 0;
}