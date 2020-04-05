#include <iostream>

int main() {

  auto add = [](auto a, auto b) {
      return a + b;
   };

  std::cout << add(5, 5) << std::endl; // for int
  std::cout << add(24.567, 456.7) << std::endl; // for float
  std::cout << add("generic", "lambdas") << std::endl; // for std::string
}
