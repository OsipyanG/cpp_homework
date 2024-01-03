#include <iostream>

#include "logger.h"

int main() {
    int n;
    std::cin >> n;

    Logger* loggers = new Logger[n];  // Создание n объектов типа Logger

    delete[] loggers;  // Уничтожение объектов (вызов деструкторов) в обратном порядке

    return 0;
}