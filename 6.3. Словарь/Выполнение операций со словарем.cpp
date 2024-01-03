#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<int, int> myMap;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x;

        if (type == 1) {
            cin >> y;
            myMap[x] = y;
        } else if (type == 2) {
            cout << (myMap.count(x) ? myMap[x] : -1) << endl;
        }
    }

    return 0;
}