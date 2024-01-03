#include <iostream>
#include <stack>
using namespace std;

int main() {
    int q;
    cin >> q;

    stack<int> myStack;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            myStack.push(x);
        } else if (type == 2) {
            myStack.pop();
        }

        if (!myStack.empty()) {
            cout << myStack.top() << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}