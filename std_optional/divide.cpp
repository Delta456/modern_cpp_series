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
