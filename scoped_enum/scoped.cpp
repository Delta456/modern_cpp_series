#include <iostream>

enum struct Num {One, Two, Three, Four, Five}; // default type is int

int main() {

    Num one = Num::One; // using :: operator for scope values

 std::cout << static_cast<int>(one) << std::endl; // using static_cast to obtain   the numerical value
    
   auto match_enum = [](Num one) {
       switch(one) {
        
        case Num::One:
         std::cout << "Num is one" << std::endl;
        break;
        
        case Num::Two:
         std::cout << "Num is two" << std::endl;
        break;
        
        case Num::Three:
         std::cout << "Num is one" << std::endl;
        break;
        
        default:
         std::`ncout << "Invalid" << std::endl;
        break;
       }

    };

  match_enum(one); // Using Num::One
   
  match_enum(Num(1)); // Casting the value to Num enum
   
}
