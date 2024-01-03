#include <iostream>
using namespace std;

int fibonacciLastDigit(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, next;
    for (int i = 2; i <= n; i++) {
        next = (a + b) % 10;
        a = b;
        b = next;
    }
    return next;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacciLastDigit(n);
    return 0;
}