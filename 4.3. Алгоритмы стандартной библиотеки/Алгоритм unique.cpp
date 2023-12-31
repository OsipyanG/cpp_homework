#include <iostream>
#include <vector>
using namespace std;

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) {
        return last;
    }

    Iter result = first;
    ++first;

    while (first != last) {
        if (*result != *first) {
            ++result;
            *result = *first;
        }
        ++first;
    }

    return ++result;
}