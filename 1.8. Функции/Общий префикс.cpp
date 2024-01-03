#include <iostream>
#include <string>
#include <vector>

std::string CommonPrefix(const std::vector<std::string>& words) {
    if (words.empty()) {
        return "";
    }

    std::string prefix = words[0];

    for (size_t i = 1; i < words.size(); i++) {
        size_t j = 0;
        while (j < prefix.length() && j < words[i].length() && prefix[j] == words[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
    }

    return prefix;
}