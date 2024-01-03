#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> concatenateSequences(const std::vector<std::vector<int>>& sequences) {
    std::vector<int> concatenated;

    for (const auto& sequence : sequences) {
        std::copy(sequence.begin(), sequence.end(), std::back_inserter(concatenated));
    }

    std::sort(concatenated.begin(), concatenated.end());

    return concatenated;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> sequences(n);

    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;

        sequences[i].resize(m);
        for (int j = 0; j < m; j++) {
            std::cin >> sequences[i][j];
        }
    }

    std::vector<int> concatenated = concatenateSequences(sequences);

    for (int element : concatenated) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}