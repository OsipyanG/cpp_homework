#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int W, n;
    std::cin >> W >> n;

    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i][w], dp[i - 1][w - weights[i - 1]] + weights[i - 1]);
            }
        }
    }

    std::cout << dp[n][W] << std::endl;

    return 0;
}