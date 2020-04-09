#include <iostream>

enum class Day {Mon, Tues, Wed, Thur, Fri, Sat, Sun};

//enum Day {Mon, Tues, Wed, Thur, Fri, Sat, Sun}; // Error : Previous defination at line 3

enum Days {Mon, Tues, Wed, Thur, Fri, Sat, Sun};


int main() {
    
    Days day_scoped = Mon;
    int num = day_scoped; // Enum converted into int
    std::cout << num << std::endl;
    
    Day days;
    days = Day::Mon;
 //   int num2 = Day; // Error: Scoped Enum cannot be converted to int implicitly
    int num_scoped = static_cast<int>(days); // Valid: Scoped Enum converted to int explicitly
    std::cout << num_scoped << std::endl;
  

    return 0;
}
