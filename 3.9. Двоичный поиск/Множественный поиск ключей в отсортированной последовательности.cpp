#include <iostream>
#include <vector>

int findIndex(const std::vector<int>& k, int num) {
    int left = 0;
    int right = k.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (k[mid] == num) {
            return mid;
        } else if (k[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> k(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k[i];
    }

    int m;
    std::cin >> m;

    std::vector<int> q(m);
    for (int i = 0; i < m; i++) {
        std::cin >> q[i];
    }

    for (int i = 0; i < m; i++) {
        int index = findIndex(k, q[i]);
        std::cout << index << " ";
    }

    return 0;
}