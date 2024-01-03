#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> mySet;

    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            mySet.insert(x);
        } else if (type == 2) {
            cout << mySet.count(x) << endl;
        }
    }

    return 0;
}