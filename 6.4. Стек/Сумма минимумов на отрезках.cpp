#include <deque>
#include <iostream>
using namespace std;

void findMinSum(int arr[], int n, int k) {
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] <= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    long long sum = 0;
    for (int i = k; i < n; i++) {
        sum += arr[dq.front()];
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] <= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    sum += arr[dq.front()];
    cout << sum << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    findMinSum(arr, n, k);
    return 0;
}