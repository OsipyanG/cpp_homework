#include <iostream>
#include <vector>

std::vector<int> findCoinSet(int money) {
    std::vector<int> coins = {50, 20, 10, 5, 1};
    std::vector<int> coinSet;

    for (int coin : coins) {
        while (money >= coin) {
            money -= coin;
            coinSet.push_back(coin);
        }
    }

    return coinSet;
}

int main() {
    int money;
    std::cin >> money;

    std::vector<int> coinSet = findCoinSet(money);

    std::cout << coinSet.size() << std::endl;
    for (int i = 0; i < coinSet.size(); i++) {
        std::cout << coinSet[i];
        if (i != coinSet.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}