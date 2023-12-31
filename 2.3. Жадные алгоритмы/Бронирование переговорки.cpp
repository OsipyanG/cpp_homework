#include <algorithm>
#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
};

bool SortByEnd(const Interval& a, const Interval& b) { return a.end < b.end; }

int findMaxNonOverlappingIntervals(std::vector<Interval>& intervals) {
    // Сортируем интервалы по их конечным точкам
    std::sort(intervals.begin(), intervals.end(), SortByEnd);

    int count = 0;
    int lastEnd = -1;

    // Проходим по отсортированным интервалам
    for (const auto& interval : intervals) {
        // Если начало интервала больше конца предыдущего интервала,
        // то прибавляем 1 к количеству взаимно непересекающихся интервалов
        if (interval.start > lastEnd) {
            count++;
            lastEnd = interval.end;
        }
    }

    return count;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) {
        std::cin >> intervals[i].start >> intervals[i].end;
    }

    int maxNonOverlappingIntervals = findMaxNonOverlappingIntervals(intervals);

    std::cout << maxNonOverlappingIntervals << std::endl;

    return 0;
}