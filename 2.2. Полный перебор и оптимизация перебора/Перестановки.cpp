#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int p = 1;
    for (int i = 1; i <= n; i++) {
        p *= i;
    }

    std::cout << p << std::endl;

    return 0;
}