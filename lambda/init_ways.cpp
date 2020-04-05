#include <iostream>

int main() {
 int add = [](int a){ return 2 + 3; }(); // using lambda then storing the value

 [](){ std::cout<< "Caliing like this also works" << std::endl; }(); 

 auto callback = [](auto a, auto b) { 
        a == b; 
    }; // using a label and then using it for various purposes
}
