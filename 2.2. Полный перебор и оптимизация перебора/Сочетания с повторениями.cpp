#include <iostream>

// Функция для вычисления факториала
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Функция для вычисления числа сочетаний с повторениями
int combinationsWithRepetition(int n, int k) {
    int numerator = factorial(n + k - 1);
    int denominator = factorial(k) * factorial(n - 1);
    return numerator / denominator;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    int result = combinationsWithRepetition(n, k);
    std::cout << result << std::endl;

    return 0;
}