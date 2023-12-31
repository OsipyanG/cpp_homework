#include <iostream>
#include <vector>

using namespace std;

// Функция для построения поля "Сапёр"
vector<vector<char>> buildField(int m, int n, const vector<pair<int, int>>& mines) {
    // Создание поля со всеми пустыми клетками
    vector<vector<char>> field(m, vector<char>(n, '0'));

    // Расстановка мин на поле
    for (const auto& mine : mines) {
        int row = mine.first - 1;  // Так как нумерация идет с единицы, а индексация с нуля
        int col = mine.second - 1;

        field[row][col] = '*';
    }

    // Подсчет количества мин на соседних клетках
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (field[row][col] == '*') {
                continue;  // Пропускаем клетку с миной
            }

            int count = 0;

            // Проверяем всех соседей текущей клетки на наличие мин
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int newRow = row + i;
                    int newCol = col + j;

                    // Проверяем, что соседняя клетка находится в пределах поля
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                        field[newRow][newCol] == '*') {
                        ++count;
                    }
                }
            }

            field[row][col] = count + '0';  // Преобразуем число в символ и заполняем текущую клетку
        }
    }

    return field;
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    vector<pair<int, int>> mines(k);
    for (int i = 0; i < k; ++i) {
        cin >> mines[i].first >> mines[i].second;
    }

    vector<vector<char>> field = buildField(m, n, mines);

    // Вывод построенного поля
    for (const vector<char>& row : field) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }

    return 0;
}