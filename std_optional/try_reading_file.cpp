#include <iostream>
#include <fstream>
#include <optional>
#include <string>

std::optional<std::string> try_reading_file(const std::string& filename) { // const to make sure it doesn't get modified
    std::ifstream file(filename); // std::ifstream for reading files 
    if (!file.is_open()) {  // if file cannot be opened
        return std::nullopt;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); //Written the content inside the file
    return content;
}

int main() {
    const std::string filename = "exmpl.txt";
    
    // try to read the file
    auto fileContent = try_reading_file(filename);

    if (fileContent.has_value()) {
        std::cout << "File content:\n" << fileContent.value() << std::endl;
    } else {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
    }

    return 0;
}
