#include <cstdarg>
#include <cstdio>
#include <string>

void c_log(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

template<typename... Args>
void logSafe(const std::string& fmt, Args... args) {
 // c_str() method turns std::string into char*
    c_log(fmt.c_str(), args...);
}

int main() {
    logSafe("Number: %d, Text: %s\n", 42, "Hello");
}
