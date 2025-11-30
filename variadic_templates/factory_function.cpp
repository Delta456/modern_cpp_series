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
