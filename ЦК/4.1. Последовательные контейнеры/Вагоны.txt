#include <iostream>
#include <list>
#include <string>
using namespace std;

void MakeTrain() {
    list<int> train;
    string command;
    int num;

    while (cin >> command) {
        if (command == "+left") {
            cin >> num;
            train.push_front(num);
        } else if (command == "+right") {
            cin >> num;
            train.push_back(num);
        } else if (command == "-left") {
            cin >> num;
            if (num >= static_cast<int>(train.size())) {
                train.clear();
            } else {
                for (int i = 0; i < num; i++) {
                    train.pop_front();
                }
            }
        } else if (command == "-right") {
            cin >> num;
            if (num >= static_cast<int>(train.size())) {
                train.clear();
            } else {
                for (int i = 0; i < num; i++) {
                    train.pop_back();
                }
            }
        }
    }

    for (int wagon : train) {
        cout << wagon << " ";
    }
    cout << endl;
}