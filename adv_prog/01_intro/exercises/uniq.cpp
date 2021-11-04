#include <iostream>
#include <string>

int main(){
    // I suppose better the while, bcs in the for loop there is
    // no update of the condiiton --> useless

    std::string line;
    unsigned int counter{0};
    std::string compare_line;

    while(std::getline(std::cin,line)){
        if(counter==0){  // first time that I see a line
            counter++;
            compare_line = line;
        }
        else{
            if(line == compare_line){  // same line as before, wait before print
                counter++;
            }
            else{  // found a different line --> utput the state about the previous line 
                std::cout << counter
                          << " "
                          << compare_line
                          << "\n";
                counter = 1;
                compare_line = line;  
            }
        }
    }
    std::cout << counter  // to output the last "state" of the program
            << " "
            << compare_line
            << std::endl; 
    return 0;
}