#include <iostream>
#include <limits>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
    std::vector<int> prev(n + 1);

    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        // Проверяем все возможные операции
        if (i % 3 == 0 && dp[i / 3] < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i / 2] < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }
        if (dp[i - 1] < dp[i]) {
            dp[i] = dp[i - 1] + 1;
            prev[i] = i - 1;
        }
    }

    std::cout << dp[n] << std::endl;

    std::vector<int> sequence;
    int current = n;
    while (current != 1) {
        sequence.push_back(current);
        current = prev[current];
    }
    sequence.push_back(1);

    for (int i = sequence.size() - 1; i >= 0; i--) {
        std::cout << sequence[i];
        if (i != 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}