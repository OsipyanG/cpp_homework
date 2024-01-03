#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::map<std::string, int> ngrams;

    for (int i = 0; i < m; ++i) {
        std::string word;
        std::cin >> word;

        for (int j = 0; j <= static_cast<int>(word.size()) - n; ++j) {
            std::string ngram = word.substr(j, n);
            ngrams[ngram]++;
        }
    }

    std::vector<std::pair<std::string, int>> ngramVector(ngrams.begin(), ngrams.end());
    std::sort(ngramVector.begin(), ngramVector.end(), [](const auto &left, const auto &right) {
        if (left.second == right.second) {
            return left.first < right.first;
        }
        return left.second > right.second;
    });

    for (const auto &entry : ngramVector) {
        std::cout << entry.first << " - " << entry.second << std::endl;
    }

    return 0;
}