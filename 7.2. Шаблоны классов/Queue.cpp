#include <queue>

template <typename T, typename Container = std::deque<T>>
class Queue {
   public:
    Queue() {}

    const T& front() const { return queue.front(); }

    T& front() { return queue.front(); }

    void pop() { queue.pop(); }

    void push(const T& value) { queue.push(value); }

    size_t size() const { return queue.size(); }

    bool empty() const { return queue.empty(); }

    bool operator==(const Queue& other) const { return queue == other.queue; }

    bool operator!=(const Queue& other) const { return queue != other.queue; }

   private:
    std::queue<T, Container> queue;
};