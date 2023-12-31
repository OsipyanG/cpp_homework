#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    std::vector<int> distances;
    for (int i = 1; i < n; ++i) {
        distances.push_back(points[i] - points[i - 1]);
    }

    std::sort(distances.begin(), distances.end(), std::greater<int>());

    int min_length = points[n - 1] - points[0];

    for (int i = 0; i < k - 1 && i < n - 1; ++i) {
        min_length -= distances[i];
    }

    std::cout << min_length << std::endl;

    return 0;
}