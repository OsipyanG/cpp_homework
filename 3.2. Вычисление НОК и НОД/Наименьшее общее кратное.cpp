#include <iostream>
using namespace std;
#include <iomanip>
long long gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }

int main() {
    double a, b;
    cin >> a >> b;
    cout << std::fixed << std::setprecision(0) << lcm(a, b);
    return 0;
}