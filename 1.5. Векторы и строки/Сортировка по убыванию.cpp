#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> lines;
    std::string line;

    // Читаем строки из ввода
    while (getline(std::cin, line)) {
        lines.push_back(line);
    }

    // Сортируем строки в убывающем порядке
    std::sort(lines.begin(), lines.end(), std::greater<std::string>());

    // Выводим отсортированные строки
    for (const std::string& str : lines) {
        std::cout << str << std::endl;
    }

    return 0;
}