#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

std::string findCommonLetters(const std::vector<std::string>& words) {
    std::unordered_set<char> commonChars(words[0].begin(), words[0].end());

    for (std::vector<std::string>::size_type i = 1; i < words.size(); i++) {
        std::unordered_set<char> wordChars(words[i].begin(), words[i].end());
        std::unordered_set<char> intersect;

        for (char ch : wordChars) {
            if (commonChars.find(ch) != commonChars.end()) {
                intersect.insert(ch);
            }
        }

        commonChars = intersect;
    }

    std::vector<char> sortedChars(commonChars.begin(), commonChars.end());
    std::sort(sortedChars.begin(), sortedChars.end());

    std::string result(sortedChars.begin(), sortedChars.end());
    return result;
}

int main() {
    std::vector<std::string> words;
    std::string word;

    while (std::cin >> word) {
        words.push_back(word);
    }

    std::string commonLetters = findCommonLetters(words);

    std::cout << commonLetters << std::endl;

    return 0;
}