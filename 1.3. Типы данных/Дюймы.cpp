#include <iostream>

int main() {
    double centimeters, inches;
    std::cin >> centimeters;
    inches = centimeters / 2.54;
    std::cout << inches << std::endl;
    return 0;
}