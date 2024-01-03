#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k = 1;
    while (n > 0) {
        n -= k;
        if (n >= 0) {
            k++;
        }
    }

    cout << k - 1 << endl;

    return 0;
}