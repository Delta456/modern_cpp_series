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
