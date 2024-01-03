#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    string query;
    priority_queue<int> pq;

    while (cin >> query) {
        if (query == "CLEAR") {
            while (!pq.empty()) {
                pq.pop();
            }
        } else if (query == "ADD") {
            int n;
            cin >> n;
            pq.push(n);
        } else if (query == "EXTRACT") {
            if (pq.empty()) {
                cout << "CANNOT" << endl;
            } else {
                int max_val = pq.top();
                pq.pop();
                cout << max_val << endl;
            }
        }
    }

    return 0;
}