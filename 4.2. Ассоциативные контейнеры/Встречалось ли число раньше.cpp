#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> numbers;
    int number;

    while (cin >> number) {
        if (numbers.count(number) > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            numbers.insert(number);
        }
    }

    return 0;
}