#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& sortedArray, int q) {
    int left = 0;
    int right = sortedArray.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (sortedArray[mid] == q) {
            return mid;
        } else if (sortedArray[mid] < q) {
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
    std::vector<int> sortedArray(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sortedArray[i];
    }
    int q;
    std::cin >> q;

    int index = binarySearch(sortedArray, q);
    std::cout << index << std::endl;
    return 0;
}