#include <algorithm>
#include <iostream>
#include <string>

bool CheckPassword(const std::string& password) {
    // Check length
    if (password.length() < 8 || password.length() > 14) {
        return false;
    }

    // Check character set
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_other = false;
    for (char c : password) {
        if (c >= 33 && c <= 126) {
            if (std::isupper(c)) {
                has_upper = true;
            } else if (std::islower(c)) {
                has_lower = true;
            } else if (std::isdigit(c)) {
                has_digit = true;
            } else {
                has_other = true;
            }
        } else {
            return false;
        }
    }

    // Check character classes
    int num_classes = has_upper + has_lower + has_digit + has_other;
    return num_classes >= 3;
}

int main() {
    std::string password;
    std::cin >> password;

    if (CheckPassword(password)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}