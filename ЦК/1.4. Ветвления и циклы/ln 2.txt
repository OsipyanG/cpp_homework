#include <iostream>

double seriesSum(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += (i % 2 == 0) ? -1.0 / i : 1.0 / i;
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;

    double sum = seriesSum(n);

    std::cout << sum << std::endl;

    return 0;
}