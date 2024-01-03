#include <iostream>

int sumDigits(int number) {
    int sum = 0;
    while (number > 0) {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }
    return sum;
}

int main() {
    int number;
    std::cin >> number;

    int sum = sumDigits(number);

    std::cout << sum << std::endl;

    return 0;
}