#include <iostream>

void printArray(int *array, int n) {
    for (int i = 0; i < n; ++i) std::cout << array[i] << std::endl;
}

void quickSort(int *array, int low, int high) {
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low) quickSort(array, low, j);
    if (i < high) quickSort(array, i, high);
}

int main() {
    int n;
    std::cin >> n;

    int array[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    quickSort(array, 0, n - 1);

    printArray(array, n);

    return 0;
}