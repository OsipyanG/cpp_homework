#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int day = 1;
    int counter = 1;
    for (int i = 1; i < n; i++) {
        if (i != n - 1)
            cout << "   ";
        else
            cout << "  ";
        counter = counter + 1;
    }
    for (int i = 1; i <= k; i++) {
        if (day < 10) {
            if (counter != 1)
                cout << "  " << day;
            else
                cout << " " << day;
        } else {
            if (counter != 1)
                cout << " " << day;
            else
                cout << day;
        }
        if (counter % 7 == 0) {
            cout << endl;
            counter = 0;
        }
        day++;
        counter++;
    }
    return 0;
}