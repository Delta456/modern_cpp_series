# Modern C++: Lambdas

Following my series from less known features of Modern C++.

## Lambdas

Lambdas are anonymous functions which are un-named functions as they are mostly needed for High Order Functions and for small purposes where they don't need much importance to be named. Lambdas were introduced in C++11 and heavily improved in the new standards. 

### Syntax

```cpp
[capture list](parameter list) -> return type (optional) {
  function body
}
```
- Capture List: Specifies how the value will be captured in the scope. 
- Parameter List: Parameters required for the function
- Return Type (Optional) : The return type of the function.
- Function Body: Body of the function.

### Basic Examples

```cpp
#include <iostream>

int main() {

 int add = [](int a){ return 2 + 3; }(); // using lambda and then storing the value

 [](){ std::cout<< "Caliing like this also works" << std::endl; }(); 

 auto callback = [](auto a, auto b) { 
        a == b;
  }; // using a label and then using it for various purposes
}
```

### Capture List

A lambda can introduce new objects in its body and can also access or capture objects from the surrounding scope. A lambda begins with the capture clause which specifies the objects that are captured and whether the capture is by value or by reference. Objects that have the ampersand (&) prefix are accessed by reference and objects that do not have it are accessed by value.

An empty capture list `[]` means that there are no variables captured. If the user wants all variables to be captured by reference then one should use `[&]` or pass by value then use `[=]`. If one wants some variable to be captured by reference or value then they should do `[foo, &var]`.

The following are valid:

```cpp
[&var, foo] // var is captured by reference and foo is passed by value.
[&, factor] // only factor is captured by value here.
[=, &total] // only total is passed by reference.
[] // no objects are passed.
``` 

### Parameter List

Like functions, parameters are optional for lambdas.

```cpp
#include <iostream>

int main() {

auto add = [](int a, int b) -> int {
      return a + b;
  };

auto print = []() {
  std::cout << "Printing from lambda." << std::endl;
};

std::cout << add(5, 5) << std::endl;
std::cout << print() << std::endl;
}
```

In this example we have `add()` lambda which takes parameter and `print()` lambda which doesn't take.

Since C++ 14, we can now use `auto` for type deceleration which can be helpful for combating more problems.

```cpp
#include <iostream>

int main() {

 auto add = [](auto a, auto b) {
      return a + b;
   };

 std::cout << add(5, 5) << std::endl; // for int
 std::cout << add(24.567, 456.7) << std::endl; // for float
 std::cout << add("generic", "lambdas") << std::endl; // for std::string
}
```

### `mutable` Specifier

`mutable` allows objects captured by value to be modified and use it's non-constant methods/functions in the specific lambda function.

```cpp
#include <iostream>

int main() {

 int var = 5;

 auto change = [var]() mutable { var = 10; std::cout << var << std::endl;  };
 change();

 std::cout << var << std::endl; // var is 5
} 
```

### Examples


#### Nested Lambdas

A simple program which takes input and then determines if they are negative or not.

```cpp
#include <iostream>

int main() {

    auto is_negative = [](int x) { return [](int y) { return y + 2; }((5) + x) <  0; }(7);
    std::cout << is_negative;

}
```

#### High Order Functions

A simple program which takes a function to sort an array in the reverse order.

```cpp
#include <iostream>
#include <algorithm>
#include <array>

int main() {

    std::array<int, 9> arr = {4, 6, 7, 5, 8, 0, 2, 3, 7 };
    std::sort(begin(arr), end(arr), [](int a, int b){ return a < b;});
    
    for (auto& i : arr) {
        std::cout << i << " ";
    }

}
```

#### Lambdas with Templates

A program which uses templates and lambdas together.

```cpp
#include <iostream>
#include <algorithm>
#include <array>

template<typename T>
void multi_by_two(std::array<T, 9>& arr) {
  std::for_each(arr.begin(), arr.end(), [](T& a){a *= 2;});
}

int main() {

    std::array<int, 9> arr = {4, 6, 7, 5, 8, 0, 2, 3, 7 };
    add_by_two(arr);
    
    for (auto& i : arr) {
        std::cout << i << " ";
    } 
}
```
### Code

All the code used in this article is available in this folder.
