#include <iostream>

// Name clashing in standard enum: activate one at a time color and led

enum color {red, yellow, green};
// enum led {red, green, value};

int main(){
    auto test = green;
    std::cout << "Test vale: " << test << std::endl;
    return 0;
}