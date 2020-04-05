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
