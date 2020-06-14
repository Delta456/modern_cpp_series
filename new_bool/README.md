# Modern C++: `and`, `or` and `not` 

Following my series from less known features of Modern C++.


In Modern C++, you can also use `and`, `or` and `not` as boolean operators which means `&&`, `||` and `!` respectively which is identical to languages like Python. They were in C but as macros but  Modern C++ introduced them as keywords.

```cpp
#include <iostream>

int main() {

std::cout << true and true << std::endl;
std::cout << true or false << std::endl;
std::cout << not true << std::endl;

 return 0;
}
```

This is exactly identical to.

```cpp
#include <iostream>

int main() {

std::cout << true && true << std::endl;
std::cout << true || false << std::endl;
std::cout << !true << std::endl;

 return 0;
}
```

You can probably use any one of the styles depending on your codebase.
