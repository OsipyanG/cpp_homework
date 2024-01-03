#include <iostream>
#include <vector>

// Функция для перемещения диска с одного стержня на другой
void moveDisk(int from, int to) { std::cout << from << " " << to << std::endl; }

// Рекурсивная функция для решения головоломки Ханойские башни
void solveHanoiTower(int n, int source, int destination, int auxiliary) {
    if (n == 1) {
        // Базовый случай: перемещение одного диска
        moveDisk(source, destination);
    } else {
        // Рекурсивный случай: перемещение n-1 диска на вспомогательный стержень,
        // перемещение оставшегося самого большого диска на целевой стержень,
        // и перемещение n-1 диска с вспомогательного стержня на целевой стержень
        solveHanoiTower(n - 1, source, auxiliary, destination);
        moveDisk(source, destination);
        solveHanoiTower(n - 1, auxiliary, destination, source);
    }
}

int main() {
    // Ввод количества дисков
    int n;
    std::cin >> n;

    // Вызов функции решения головоломки Ханойские башни
    std::cout << (1 << n) - 1 << std::endl;  // Вывод количества операций
    solveHanoiTower(n, 1, 3, 2);  // Вызов функции для решения головоломки

    return 0;
}