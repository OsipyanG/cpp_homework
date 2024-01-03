#include <iostream>

int main() {
    int month, year;
    std::cin >> month >> year;

    int days_in_month;
    if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }

    std::cout << days_in_month << std::endl;

    return 0;
}