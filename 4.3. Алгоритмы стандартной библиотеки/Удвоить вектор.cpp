#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void Duplicate(vector<T>& v) {
    size_t originalSize = v.size();
    for (size_t i = 0; i < originalSize; ++i) {
        v.push_back(v[i]);
    }
}