#pragma once

#include <random>
#include <vector>

template <typename T>
class RandomizedQueue {
public:
    void enqueue(const T& item) {
        data.push_back(item);
        if (data.size() == 1) {
            calculateNewIndex();
        }
    }

    T sample() {
        return data[randomIndex];
    }

    T dequeue() {
        T item = data[randomIndex];
        std::swap(data[randomIndex], data.back());
        data.pop_back();
        if (!data.empty()) {
            calculateNewIndex();
        }
        return item;
    }

    bool empty() const {
        return data.empty();
    }

private:
    void calculateNewIndex() {
        std::uniform_int_distribution<> dist(0, data.size() - 1);
        randomIndex = dist(rng);
    }

    std::vector<T> data;
    std::mt19937 rng{std::random_device{}()};
    int randomIndex;
};
