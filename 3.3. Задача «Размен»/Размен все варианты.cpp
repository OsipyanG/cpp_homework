#include <iostream>
#include <vector>
using namespace std;

void findCoinCombinations(int money, vector<int> coins, vector<vector<int>>& result, vector<int>& current,
                          int index) {
    if (money == 0) {
        result.push_back(current);
        return;
    }

    for (int i = index; i < coins.size(); i++) {
        if (money >= coins[i]) {
            current.push_back(coins[i]);
            findCoinCombinations(money - coins[i], coins, result, current, i);
            current.pop_back();
        }
    }
}

int main() {
    int money;
    cin >> money;

    vector<int> coins = {1, 5, 10};
    vector<vector<int>> result;
    vector<int> current;

    findCoinCombinations(money, coins, result, current, 0);

    cout << result.size() << endl;
    for (int i = result.size() - 1; i >= 0; --i) {
        std::cout << result[i].size() << " ";  // Выводим количество монет в данном наборе
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];  // Выводим номиналы монет в данном наборе
            if (j != result[i].size() - 1) {
                cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}