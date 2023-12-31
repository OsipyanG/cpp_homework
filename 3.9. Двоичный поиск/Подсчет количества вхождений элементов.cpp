#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // Если элемент не найден
}

vector<int> countOccurrences(const vector<int>& k, const vector<int>& q) {
    vector<int> counts(q.size(), 0);

    for (int i = 0; i < q.size(); i++) {
        int index = binarySearch(k, q[i]);

        if (index != -1) {
            int count = 1;

            // Подсчитываем количество повторяющихся значений
            int left = index - 1;
            while (left >= 0 && k[left] == q[i]) {
                count++;
                left--;
            }

            int right = index + 1;
            while (right < k.size() && k[right] == q[i]) {
                count++;
                right++;
            }

            counts[i] = count;
        }
    }

    return counts;
}

int main() {
    int n;
    cin >> n;

    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    int m;
    cin >> m;

    vector<int> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i];
    }

    vector<int> result = countOccurrences(k, q);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}