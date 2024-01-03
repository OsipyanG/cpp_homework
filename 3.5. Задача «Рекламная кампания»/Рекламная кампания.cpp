#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    vector<int> clicks(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> clicks[i];
    }

    sort(prices.rbegin(), prices.rend());
    sort(clicks.rbegin(), clicks.rend());

    long long maxProfit = 0;

    for (int i = 0; i < n; i++) {
        maxProfit += (long long)prices[i] * clicks[i];
    }

    cout << maxProfit << endl;

    return 0;
}
