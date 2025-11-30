# Modern C++: Variadic Templates

This follows my series to cover lesser known features of Modern C++

Today, we have variadic templates, which is an improvement over variadic arguments (`...`), a type of argument that can take variable arguments.

Before we start with variadic templates, an introduction to variadic arguments is **required**.

### Variadic Arguments

Variadic arguments have been around since **the time of C and old C++** but it has a lot of limitations, which can be seen in the code demonstration below:

```c++
#include <iostream>
#include <cstdarg>

void printNumbers(int count, ...) {
    va_list args; // Hold and make argument list with capacity "count"
    va_start(args, count); // Start processing variable args

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int); // Get next argument
        std::cout << num << " ";
    }

    va_end(args); // Clean up
    std::cout << std::endl;
}

int main() {
    printNumbers(1, 2, 3, 4); // Works completely fine
    printNumbers(4, 34, '4', 12.3, "12"); // It doesn't raise error but IT SHOULD!
    return 0;
}
```

As can be seen above:

- Number of arguments need to be provided manually (most of the time, it's **dynamic**)
- The compiler doesn't raise any error if variable arguments have **different** types
- Need to import header file `<cstdarg>` to use them
- It only works with basic primitive types (`std::string` is **NOT**)

This is very limited and doesn't work for the **Modern C++** world where classes, objects and templates are used all the time.

### Variadic Templates

Variadic Templates were introduced in **C++  11** to eliminate the limitations of variadic arguments by providing type safety, dynamic argument length and lesser usage of macros.

The following code is a basic example of variadic templates used to sum numbers:

```c++
#include <iostream>

template<typename... Args>
auto sum(Args... args) {
    return (args + ...); // Fold expression (C++17)
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5) << std::endl; // Output: 15
    std::cout << sum(2.5, 3.5) << std::endl;      // Output: 6.0
}

```

The function `sum` has a packet parameter `Args... args` which can accept any number of arguments

`(args + ...)` is a fold expression, introduced in **C++ 17**, and is a clean and concise way to perform operations over variadic templates.

This code is then expanded to `((1 + 2) + 3) + 4 + 5`, which returns the value of `15`.

### More than Functions

Variadic Templates have more usage than just using them with basic functions. They can be used in situations like:

1. Logical AND / OR Boolean Operations

```c++
#include <iostream>

template<typename... Bools>
bool allTrue(Bools... bs) {
    return (bs && ...);
}

template<typename... Bools>
bool anyTrue(Bools... bs) {
    return (bs || ...);
}

int main() {
    std::cout << allTrue(true, true, false) << "\n"; // false
    std::cout << anyTrue(false, false, true) << "\n"; // true
}
```

This operation is used in flag evaluation and validation checks

2. Calling a Function on Each Argument

```c++
#include <iostream>

void log(int x) { std::cout << "[int] " << x << "\n"; }
void log(const char* s) { std::cout << "[str] " << s << "\n"; }

template<typename... Args>
void logAll(Args... args) {
    (log(args), ...); // C++17 fold expression with comma
}

int main() {
    logAll(1, "hello", 42, "world");
}
```

The code snippet logs all the arguments according to their type.

```bash
[int] 1
[str] hello
[int] 42
[str] world

```

3. Custom Factory functions

```cpp
#include <memory>
#include <utility>
#include <iostream>

template<typename T, typename... Args>
std::unique_ptr<T> make_instance(Args&&... args) {
 return std::make_unique<T>(std::forward<Args>(args)...); // preserve the argument was originally passed
}

  
struct Foo {
 Foo(int x, const std::string& y) {
  std::cout << "Foo constructed: " << x << ", " << y << "\n"
 }
};

  

int main() {
 auto f = make_instance<Foo>(10, "bar");
}
```

The code snippet is a custom factory function which makes a class with any number of parameters.

```bash
Foo constructed: 10, bar
```

4. Real life applications

Variadic templates are heavily used by C++ STL such as `std::tuple`, `std::pair`, `std::array` `std::make_unique`, `std::make_shared` libraries

### When to use C variadic arguments `va_arg`

- Working with C functions such as `printf`, `scanf`, `syslog`, etc
- Extending C code on top of C++ code
- Writing bindings for legacy support

### Variadic Arguments to Variadic Templates

Variadic Arguments can easily be wrapped with Variadic Templates **incase** there's a need to do it:

```cpp
#include <cstdarg>
#include <cstdio>
#include <string>

void c_log(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

template<typename... Args>
void logSafe(const std::string& fmt, Args... args) {
 // c_str() method turns std::string into char*
    c_log(fmt.c_str(), args...);
}

int main() {
    logSafe("Number: %d, Text: %s\n", 42, "Hello");
}

```

This example demonstrates how a C-style variadic, which logs a message, is wrapped by a Variadic Template.

### Conclusion

- Use **C variadic functions** only when you need to **interop with legacy C code** or **third-party libraries**.  
- For all modern C++ code, prefer **variadic templates** for type safety, maintainability, and cleaner syntax.  
- You can even **wrap** C variadic functions with variadic templates when needed.

### Code

All the code used in this article is available here.
