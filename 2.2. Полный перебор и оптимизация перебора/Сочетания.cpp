#include <iostream>
#include <vector>

// Функция для вычисления числа сочетаний
unsigned long long combination(int n, int k) {
    std::vector<std::vector<unsigned long long>> dp(n + 1, std::vector<unsigned long long>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int main() {
    int n, k;
    std::cin >> n >> k;

    unsigned long long result = combination(n, k);

    std::cout << result << std::endl;

    return 0;
}