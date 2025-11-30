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
