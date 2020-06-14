# Modern C++: enum class|struct

Following my series from less known features of Modern C++.

I saw this post the other day and I agreed with all his reasoning why `enum` in TypeScript aren't safe. (Read this article for more information.)

[TypeScript Enum](https://dev.to/bnevilleoneill/why-typescript-enums-suck-54kn)

To solve these problems C++ 11 introduces `enum class` or `enum struct`. If you are lazy to read that post then the old enum had the following problems:

- Conventional enums implicitly convert to int, causing errors when someone does not want an enumeration to act as an integer.
- Conventional enums export their enumerators to the surrounding scope, causing name clashes.
- The underlying type of an enum cannot be specified, causing confusion, compatibility problems, and makes forward declaration impossible.  

## Syntax

```cpp
enum [class|struct] [identifier] [:type] {list};
```

Both `class` and `struct` have the same meaning here (for no damn reason).

## Usage

```cpp
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
```

Just like `enum` the values should be of literal type. There will be name clashes if we have `enum` and `enum class|struct` of the same name.


### `enum` V/S `enum class|struct`

- `enum` elements are accessed by `.` and `enum class|struct` are accessed by `::`.
- There can be clashes with other `enum` whereas `enum class|struct` are scoped so there are no clashes.
-  `enum` can be converted into other `enum` but this isn't the case for `enum struct|class`.

```cpp
#include <iostream>

enum class Day {Mon, Tues, Wed, Thur, Fri, Sat, Sun};

//enum Day {Mon, Tues, Wed, Thur, Fri, Sat, Sun}; // Error : Previous defination at line 2

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
```

If we un-commented the some code above then the program will raise errors.

### Code 

All the code used in this article is available in this folder.
