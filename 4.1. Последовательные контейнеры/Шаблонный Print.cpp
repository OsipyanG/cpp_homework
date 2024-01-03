#include <iostream>
#include <string>
#include <vector>

template <typename T>
void Print(const T& container, const std::string& delimiter) {
    bool first = true;
    for (const auto& element : container) {
        if (!first) {
            std::cout << delimiter;
        }
        std::cout << element;
        first = false;
    }
    std::cout << std::endl;
}