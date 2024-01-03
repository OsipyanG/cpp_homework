#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

bool compareDistance(const Point& p1, const Point& p2) {
    double dist1 = sqrt(p1.x * p1.x + p1.y * p1.y);
    double dist2 = sqrt(p2.x * p2.x + p2.y * p2.y);
    return dist1 < dist2;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compareDistance);

    for (const Point& point : points) {
        cout << point.x << " " << point.y << endl;
    }

    return 0;
}