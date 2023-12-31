#include <utility>
#include <vector>

template <typename T>
class Table {
   public:
    Table(size_t rows, size_t cols) : data(rows, std::vector<T>(cols)) {}

    const std::vector<T>& operator[](size_t index) const { return data[index]; }

    std::vector<T>& operator[](size_t index) { return data[index]; }

    void resize(size_t rows, size_t cols) {
        data.resize(rows);
        for (auto& row : data) {
            row.resize(cols);
        }
    }

    std::pair<size_t, size_t> size() const { return {data.size(), data.empty() ? 0 : data[0].size()}; }

   private:
    std::vector<std::vector<T>> data;
};