#include <iostream>
#include <vector>

std::vector<std::vector<int>> createFirstGraph(int n, const std::vector<std::vector<int>>& routes) {
    std::vector<std::vector<int>> firstGraph(n, std::vector<int>(n, 0));

    for (const auto& route : routes) {
        for (int i = 0; i < route.size() - 1; ++i) {
            firstGraph[route[i] - 1][route[i + 1] - 1] = 1;
            firstGraph[route[i + 1] - 1][route[i] - 1] = 1;
        }
    }

    return firstGraph;
}

std::vector<std::vector<int>> createSecondGraph(int n, const std::vector<std::vector<int>>& routes) {
    std::vector<std::vector<int>> secondGraph(n, std::vector<int>(n, 0));

    for (const auto& route : routes) {
        for (int i = 0; i < route.size(); ++i) {
            for (int j = i + 1; j < route.size(); ++j) {
                secondGraph[route[i] - 1][route[j] - 1] = 1;
                secondGraph[route[j] - 1][route[i] - 1] = 1;
            }
        }
    }

    return secondGraph;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> routes(m);
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        routes[i].resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> routes[i][j];
        }
    }

    auto firstGraph = createFirstGraph(n, routes);
    auto secondGraph = createSecondGraph(n, routes);

    // Вывод матриц смежности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << firstGraph[i][j];
            if (j < n - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << secondGraph[i][j];
            if (j < n - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}