#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, L;
    std::cin >> n >> L;

    std::vector<int> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    int covered = points[0];
    int segments = 1;
    for (int i = 1; i < n; i++) {
        if (points[i] - covered > L) {
            // Текущая точка не покрыта отрезком, нужен новый отрезок
            covered = points[i];
            segments++;
        }
    }

    std::cout << segments << std::endl;

    return 0;
}