#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();     // количество строк
    int m = matrix[0].size();  // количество столбцов

    std::vector<std::vector<int>> transposed(m, std::vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}