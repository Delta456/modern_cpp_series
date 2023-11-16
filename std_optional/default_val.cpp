#include <optional>
#include <iostream>

int main() {
    std::optional<int> value;

    int result = value.value_or(42);  // Assigns 42 if value is not present

    std::cout << "Result: " << result << std::endl;

    return 0;
}
