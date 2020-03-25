#include <iostream>

int main()
{
  switch (int i = 0)
    {
    case 0:
      std::cout << "i is negative";
      break;

    case 1:
      std::cout << "i is one";

    default:
      std::cout << "invalid";
      break;
    }
  //std::cout << i << std::endl;        // i will not be available here
}
