#include <iostream>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int n;
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}