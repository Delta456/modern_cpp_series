# Modern C++: Temp Vars on Switch/If

Following my series from less known features of Modern C++.

This feature is small and minor one so this article is small but an important for sure.

From C++ 17 you can declare temporary variables on `if` and `switch` statements just like loops. As the variables are temporary, you can't access those variables as they are only declared in the `if` or `switch` block.

### If Statement

```cpp
#include <iostream>

int main()
{
  if (int i = 0; i > 0)
    {
      std::cout << "i is positive" << std::endl;
    }
  else if (i < 0)
    {
      std::cout << "i is negative" << std::endl;
    }
  else
    {
      std::cout << "i is zero" << std::endl;
    }
 // std::cout << i << std::endl;	// i will not be available here
}
```

### Switch Statement

```cpp
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
```
If we comment out the last line of both of the examples then an error will be raised.

```error
main.cpp: In function ‘int main()’:
main.cpp:26:17: error: ‘i’ was not declared in this scope
    std::cout << i << std::endl;        // i will not be available here
```
