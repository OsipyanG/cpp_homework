#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> firstArray(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> firstArray[i];
    }

    for (int i = 0; i < k; ++i) {
        int num;
        std::cin >> num;
        auto it = std::lower_bound(firstArray.begin(), firstArray.end(), num);
        if (it == firstArray.begin()) {
            std::cout << *it << std::endl;
        } else if (it == firstArray.end()) {
            std::cout << *(it - 1) << std::endl;
        } else {
            if (*it - num < num - *(it - 1)) {
                std::cout << *it << std::endl;
            } else {
                std::cout << *(it - 1) << std::endl;
            }
        }
    }

    return 0;
}