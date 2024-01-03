#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seats[i];
    }

    std::vector<int> guests(n);
    for (int i = 0; i < n; i++) {
        guests[seats[i] - 1] = i + 1;
    }

    for (int guest : guests) {
        std::cout << guest << " ";
    }
    std::cout << std::endl;

    return 0;
}