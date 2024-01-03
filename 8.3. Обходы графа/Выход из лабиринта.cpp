#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Структура для представления состояния клетки лабиринта
struct Cell {
    int row;
    int col;
    int distance;
    string path;
};

// Функция для поиска кратчайшего пути в лабиринте
void findShortestPath(vector<vector<char>>& maze, int startRow, int startCol) {
    int numRows = maze.size();
    int numCols = maze[0].size();

    // Создаем двумерный массив для хранения информации о посещенных клетках
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

    // Создаем очередь для хранения состояний клеток, которые нужно посетить
    queue<Cell> q;

    // Стартовая клетка
    Cell startCell = {startRow, startCol, 0, ""};
    q.push(startCell);
    visited[startRow][startCol] = true;

    // Перебираем все состояния клеток в очереди
    while (!q.empty()) {
        Cell currentCell = q.front();
        q.pop();

        // Проверяем, достигли ли мы выхода из лабиринта
        if (maze[currentCell.row][currentCell.col] == 'F') {
            cout << currentCell.distance << endl;
            cout << currentCell.path << endl;
            return;
        }

        // Возможные ходы: вверх, вниз, вправо, влево
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        string moves[] = {"U", "D", "R", "L"};

        for (int i = 0; i < 4; i++) {
            int newRow = currentCell.row + dr[i];
            int newCol = currentCell.col + dc[i];

            // Проверяем, не выходит ли новая клетка за границы лабиринта и не является ли она стеной или уже
            // посещенной
            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols &&
                maze[newRow][newCol] != '#' && !visited[newRow][newCol]) {
                // Создаем новое состояние клетки с увеличенным на 1 расстоянием и путем
                Cell nextCell = {newRow, newCol, currentCell.distance + 1, currentCell.path + moves[i]};
                q.push(nextCell);
                visited[newRow][newCol] = true;
            }
        }
    }

    // Если выхода из лабиринта не существует
    cout << -1 << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Чтение лабиринта
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // Поиск входа в лабиринт
    int startRow, startCol;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    // Вызов функции поиска кратчайшего пути
    findShortestPath(maze, startRow, startCol);

    return 0;
}