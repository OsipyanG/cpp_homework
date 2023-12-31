#include <iostream>
#include <vector>

int main() {
    // Считываем размер комнаты
    int n, m;
    std::cin >> n >> m;

    // Считываем план комнаты
    std::vector<std::vector<char>> room(n, std::vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> room[i][j];
        }
    }

    // Считываем начальные координаты робота
    int r, c;
    std::cin >> r >> c;

    // Считываем количество действий пылесоса и план движений
    int q;
    std::cin >> q;
    std::string actions;
    std::cin >> actions;

    // Заводим множество посещенных клеток
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    // Устанавливаем начальные координаты и направление робота
    int curR = r - 1;  // Приводим к нумерации с нуля
    int curC = c - 1;  // Приводим к нумерации с нуля
    int dir = 0;       // 0 - вверх, 1 - вправо, 2 - вниз, 3 - влево

    // Посещаем стартовую клетку
    visited[curR][curC] = true;

    // Обрабатываем каждое действие пылесоса
    for (int i = 0; i < q; i++) {
        char action = actions[i];
        if (action == 'L') {
            dir =
                (dir + 3) % 4;  // Поворот налево - изменяем направление против часовой стрелки на 90 градусов
        } else if (action == 'R') {
            dir = (dir + 1) % 4;  // Поворот направо - изменяем направление по часовой стрелке на 90 градусов
        } else if (action == 'M') {
            // Движение вперед
            int nextR = curR;
            int nextC = curC;

            if (dir == 0) {
                nextR--;
            } else if (dir == 1) {
                nextC++;
            } else if (dir == 2) {
                nextR++;
            } else if (dir == 3) {
                nextC--;
            }

            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && room[nextR][nextC] != '#') {
                curR = nextR;
                curC = nextC;
                visited[curR][curC] = true;
            }
        }
    }

    // Подсчитываем количество посещенных клеток
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}