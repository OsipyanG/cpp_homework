#include <algorithm>
#include <iostream>
#include <vector>

int max_number_of_gifts(int n, int s, std::vector<int>& prices) {
    std::sort(prices.begin(), prices.end());

    int count = 0;
    int total_cost = 0;

    for (int i = 0; i < n; i++) {
        if (total_cost + prices[i] <= s) {
            count++;
            total_cost += prices[i];
        } else {
            break;
        }
    }

    return count;
}

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    int result = max_number_of_gifts(n, s, prices);

    std::cout << result << std::endl;

    return 0;
}