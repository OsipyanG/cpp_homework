#include <iostream>
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result;
    int size = tokens.size();
    if (size == 0) {
        return result;
    }
    result = tokens[0];
    for (int i = 1; i < size; i++) {
        result += delimiter + tokens[i];
    }
    return result;
}
