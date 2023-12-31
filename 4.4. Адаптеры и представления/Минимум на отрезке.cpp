#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    priority_queue<pair<int, int>>
        window;  // Создаем очередь с приоритетом, где будем хранить пары (число, его позиция)

    for (int i = 0; i < k; i++) {
        window.push({-sequence[i], i});  // Заполняем очередь первыми k элементами
    }

    cout << -window.top().first << " ";  // Выводим минимум из первого "окна"

    for (int i = k; i < n; i++) {
        window.push({-sequence[i], i});  // Добавляем новый элемент в очередь
        while (window.top().second <= i - k) {
            window.pop();  // Удаляем элементы, которые уже не входят в "окно"
        }
        cout << -window.top().first << " ";  // Выводим минимум для каждого положения "окна"
    }

    return 0;
}