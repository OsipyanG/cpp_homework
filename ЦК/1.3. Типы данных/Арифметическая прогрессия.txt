#include <iostream>

int main() {
    unsigned long long n;
    std::cin >> n;
    unsigned long long sum = n * (n + 1) / 2;
    std::cout << sum << "\n";
    return 0;
}