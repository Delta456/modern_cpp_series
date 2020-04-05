#include <iostream>

int main() {
    auto is_negative = [](int x) { return [](int y) { return y + 2; }((5) + x) <  0; }(7);
    std::cout << is_negative;
}
