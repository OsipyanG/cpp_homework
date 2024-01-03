#include <iostream>
#include <queue>
using namespace std;

int main() {
    int q;
    cin >> q;

    queue<int> myQueue;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            myQueue.push(x);
        } else if (type == 2) {
            myQueue.pop();
        }

        if (!myQueue.empty()) {
            cout << myQueue.front() << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}