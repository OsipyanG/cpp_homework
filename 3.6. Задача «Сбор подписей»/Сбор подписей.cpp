#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Segment {
    int left, right;
};

bool compareSegments(const Segment& s1, const Segment& s2) { return s1.right < s2.right; }

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].left >> segments[i].right;
    }
    sort(segments.begin(), segments.end(), compareSegments);

    vector<int> points;
    int currentPoint = segments[0].right;
    points.push_back(currentPoint);
    for (int i = 1; i < n; i++) {
        if (currentPoint < segments[i].left) {
            currentPoint = segments[i].right;
            points.push_back(currentPoint);
        }
    }

    int numPoints = points.size();
    cout << numPoints << endl;
    for (int i = 0; i < numPoints; i++) {
        cout << points[i];
        if (i != numPoints - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}