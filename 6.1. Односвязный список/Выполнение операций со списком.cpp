#include <iostream>
#include <list>

int main() {
    int q;
    std::cin >> q;

    std::list<int> myList;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        std::cin >> type;

        if (type == 1) {
            std::cin >> x >> y;
            if (x == 0) {
                myList.push_front(y);
            } else {
                auto it = myList.begin();
                std::advance(it, x - 1);
                myList.insert(std::next(it), y);
            }
        } else if (type == 2) {
            std::cin >> x;
            auto it = myList.begin();
            std::advance(it, x - 1);
            std::cout << *it << std::endl;
        } else if (type == 3) {
            std::cin >> x;
            auto it = myList.begin();
            std::advance(it, x - 1);
            myList.erase(it);
        }
    }

    return 0;
}
