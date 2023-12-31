#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int minCoins(int money) {
    vector<int> dp(money + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= money; i++) {
        if (i - 1 >= 0) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }
        if (i - 3 >= 0) {
            dp[i] = min(dp[i], dp[i - 3] + 1);
        }
        if (i - 4 >= 0) {
            dp[i] = min(dp[i], dp[i - 4] + 1);
        }
    }
    return dp[money];
}

int main() {
    int money;
    cin >> money;
    cout << minCoins(money) << endl;
    return 0;
}
