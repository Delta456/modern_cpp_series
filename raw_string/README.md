# Modern C++: Raw Strings 

Following my series from less known features of Modern C++.


From C++11, you now have raw strings which is much needed when writing strings of special characters or escape sequences like `\n`, `\r`, `\` etc.


## When this problem arises 

In the following code we have two strings which represent a path and a special string respectively. We need the output to be `C:\User\Home\Folder` and `newline\n`.

```cpp
#include <iostream>
#include <string>

int main() {

std::string dir = "C:\User\Home\Folder";  
std::string special_str = "newline\n"; 

std::cout << dir << std::endl;
std::cout << special_str << std::endl;

 return 0;
}
``` 

Output:

```error
main.cpp: In function ‘int main()’:
main.cpp:15:19: error: incomplete universal character name \U
 std::string dir = "\User\Home\Folder";
                   ^~~~~~~~~~~~~~~~~~~
main.cpp:15:19: warning: unknown escape sequence: '\H'
main.cpp:15:19: warning: unknown escape sequence: '\F'
```

This is something that we didn't expected to happen. Thus, a problem like this comes when we need string with special characters.

## Possible Solutions

### Using `\\`in strings 

In Traditional C++, you had to do this to solve this problem: 

```cpp
#include <iostream>
#include <string>

int main() {

std::string dir = "C:\\User\\Home\\Folder";
std::string special_str = "newline\\n";

std::cout << dir << std::endl;
std::cout << special_str << std::endl;

 return 0;
}
```

Output:

```console
C:\User\Home\Folder                                                                                                                                   
newline\n
```  

In the above we had to do `\` twice to make the compiler ignore the escape sequence but this looks ugly IMO. 


### Using `R` for raw string

From C++11 on-wards, we can write the code more easily and fancy with the help of `R` in-front of the string and parenthesis in the string which treats special characters as literal.

```cpp
#include <iostream>
#include <string>

int main() {

std::string dir = R"(C:\User\Home\Folder)";
std::string special_str = R"(newline\n)";

std::cout << dir << std::endl;
std::cout << special_str << std::endl;

 return 0;
}                                                                                                                                 
```

Output:

```console
C:\User\Home\Folder                                                                                                                                   
newline\n
``` 

In the above code we have used `R"()"` to treat strings with special characters as literals which makes the code compile and looks fancy, easy and debug. 

I will say that people who use Modern C++ must go with the second method because it's modern and many people will learn it when they are reading code but the first method should also be known for learning purposes.

I hope this clarifies about raw strings in Modern C++ and if you have any question then please don't hesitate to ask!

## Acknowledgments 

I thank [Modern C++ Book](https://changkun.de/modern-cpp/), [C++ Preference](https://en.cppreference.com/w/) for providing the more detailed information. I wouldn't have been able to make this post if these resources weren't present.
