#include <iostream>
#include <fstream>
#include <string>

void read_file(const char* file_name) {
    std::ifstream instructionFile(file_name);

    std::string instruction;
    int i = 0;

    while (std::getline(instructionFile, instruction)) {
        // Skip empty lines
        if (instruction.empty()) {
            continue;
        }

        try {
            int out = std::stol(instruction, nullptr, 16);
            std::cout << out << std::endl;
            i++;
        } catch (const std::invalid_argument& e) {
            break;
        }
    }
}

int main() {
    const char* file_name = "example.data.txt";
    read_file(file_name);
    return 0;
}
