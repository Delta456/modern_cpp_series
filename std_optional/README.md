# Modern C++: std::optional

Hey, I am finally started to continue my series from less-known features of Modern C++.

### The Problem

There are times when you want to return a potential value like NULL or some error to indicate a problem, for example.

```cpp
int check_name(std::string name) {
     if (name == "Tom")
         return 0;
     else
         return -1; //  Used to indicate invalid input 
}
```

But, when calling this function one would have to check if `-1` is returned or not according to the input.

```cpp
code = check_name("Same")
if (code == -1) {
    ...
}
```

Which makes the code unreadable and inconsistent if other values are returned in rest functions.

That's where `std::optional` comes to the rescue!

### `std::optional`

`std::optional` is a feature introduced in C++ 17 which is used to represent optional values i.e. the possibility of **having a value** or not having a value in a **type-safe manner**.

#### Syntax

```cpp
std::optional<T> opt_var;
```

where `T` represents the optional value to be stored.

**Methods**:

- `has_value`: checks whether the object contains a value
- `value`: returns the contained value
- `value_or`: returns the contained value if available, another value otherwise 

#### Usage

- Check if one number can divide another number or not

```cpp
#include <iostream>
#include <optional>

std::optional<int> divide(int num1, int num2) {
    if (num2 != 0) {
        return num1/num2;
    }
    return std::nullopt; // Indicates no type-safe value
}

int main() {
    auto result = divide(10, 2); // To infer into std::optional<int>, used to save time 
    if (result.has_value()) {  // has_value checks if a type-value is returned
        std::cout << "Result: " << result.value() << std::endl; // value returns the value as function arguments are correct
    } else {
        std::cout << "Division by zero" << std::endl;
    }

    return 0;
}
```

- Simplifying error handling; in scenarios where you want to read a file, parse strings then convert them into integers and format them.

```cpp
#include <iostream>
#include <fstream>
#include <optional>
#include <string>

std::optional<std::string> try_reading_file(const std::string& filename) { // const to make sure it doesn't get modified
    std::ifstream file(filename); // std::ifstream for reading files 
    if (!file.is_open()) {  // if file cannot be opened
        return std::nullopt;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); //Written the content inside the file
    return content;
}

int main() {
    const std::string filename = "exmpl.txt";
    
    // try to read the file
    auto fileContent = try_reading_file(filename);

    if (fileContent.has_value()) {
        std::cout << "File content:\n" << fileContent.value() << std::endl;
    } else {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
    }

    return 0;
}
```

- Checking and changing the default value

```cpp
#include <optional>
#include <iostream>

int main() {
    std::optional<int> value;

    int result = value.value_or(42);  // Assigns 42 if value is not present

    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

These are the most common usages of `std::optional` and more usages can seen by reading C++ code of many open source organizations.

### Comparison from other languages

- Rust has an `Option` enum to implement optionals
- Go doesn't have optional so it uses a type called `error` for error handling
- Java also implements optional via generics/classes
- V implements `option` for returning optional values and `result` for resultant values.

### Conclusion

Whenever you possibly have to denote an **answer** or **value-or-not-value**, it is recommended to use `std::optional` unless you are working with legacy code where integers are used to represent. It also increases the capacity to **describe complex problems**, **readability** and also **handle errors gracefully**.

### Code

All the code used in this article is available in this repo.
