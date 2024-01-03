#include <iostream>
using namespace std;

int fibonacci(int n) {
    int a = 0, b = 1, next = 0;
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return (n == 0) ? a : b;
}

int main() {
    int n;

    cin >> n;
    cout << fibonacci(n);
    return 0;
}