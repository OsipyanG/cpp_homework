#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canCover(const vector<int>& points, int k, int length) {
    int count = 1;  // Количество отрезков, которыми покрыты точки
    int lastPoint = points[0];
    for (int i = 1; i < points.size(); i++) {
        if (points[i] - lastPoint > length) {
            count++;
            lastPoint = points[i];
        }
    }
    return count <= k;
}

int binarySearch(const vector<int>& points, int k) {
    int left = 0;  // Начальное значение минимальной длины отрезка
    int right = points.back() - points.front();  // Начальное значение максимальной длины отрезка

    while (left < right) {
        int mid = (left + right) / 2;
        if (canCover(points, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int minSegmentLength = binarySearch(points, k);
    cout << minSegmentLength << endl;

    return 0;
}