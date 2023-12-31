#include <iostream>
#include <utility>
#include <vector>

std::pair<int, int> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int k = matrix[0].size();

    int maxElement = matrix[0][0];
    int maxRowIndex = 0;
    int maxColIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRowIndex = i;
                maxColIndex = j;
            }
        }
    }

    return std::make_pair(maxRowIndex, maxColIndex);
}