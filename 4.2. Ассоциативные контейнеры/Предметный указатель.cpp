#include <iostream>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::map<int, std::set<std::string>> keywords;

    for (int i = 0; i < n; ++i) {
        std::string word;
        int page;
        std::cin >> word >> page;
        keywords[page].insert(word);
    }

    for (const auto& entry : keywords) {
        std::cout << entry.first << " ";
        for (const auto& word : entry.second) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}