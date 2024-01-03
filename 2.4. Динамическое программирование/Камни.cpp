#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::string>> dp(n + 1, std::vector<std::string>(m + 1, "Win"));

    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i < n && dp[i + 1][j] == "Loose") {
                dp[i][j] = "Win";
            } else if (j < m && dp[i][j + 1] == "Loose") {
                dp[i][j] = "Win";
            } else if (i < n && j < m && dp[i + 1][j + 1] == "Loose") {
                dp[i][j] = "Win";
            } else {
                dp[i][j] = "Loose";
            }
        }
    }

    std::cout << dp[0][0] << std::endl;

    return 0;
}