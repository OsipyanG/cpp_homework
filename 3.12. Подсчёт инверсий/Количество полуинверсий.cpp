#include <iostream>
#include <vector>

long long merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] >= arr[j]) {
            inversions += mid - i + 1;  // Увеличиваем счетчик полуинверсий
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; ++p) {
        arr[p] = temp[p];
    }

    return inversions;
}

long long mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

long long countSemiInversions(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> temp(n);
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    long long semiInversions = countSemiInversions(arr);
    std::cout << semiInversions << std::endl;

    return 0;
}