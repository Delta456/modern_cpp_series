#include <iostream>

int main() {

  int var = 5;

  auto change = [var]() mutable { var = 10; std::cout << var << std::endl;  }; // var is 10
  change();

  std::cout << var << std::endl; // var is 5
} 
