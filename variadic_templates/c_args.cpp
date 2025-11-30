#include <iostream>
#include <cstdarg>

void printNumbers(int count, ...) {
    va_list args; // Hold and make argument list with capacity "count"
    va_start(args, count); // Start processing variable args

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int); // Get next argument
        std::cout << num << " ";
    }

    va_end(args); // Clean up
    std::cout << std::endl;
}

int main() {
    printNumbers(1, 2, 3, 4); // Works completely fine
    printNumbers(4, 34, '4', 12.3, "12"); // It doesn't raise error but IT SHOULD!
    return 0;
}
