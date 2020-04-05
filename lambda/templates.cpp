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
