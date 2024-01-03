#include <iostream>
#include <vector>

int min_transpositions(std::vector<int>& p) {
    int n = p.size();
    int count = 0;

    for (int i = 1; i < n; ++i) {
        int key = p[i];
        int j = i - 1;

        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            count++;
            j--;
        }

        p[j + 1] = key;
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    int min_transpositions_count = min_transpositions(p);
    std::cout << min_transpositions_count << std::endl;

    return 0;
}