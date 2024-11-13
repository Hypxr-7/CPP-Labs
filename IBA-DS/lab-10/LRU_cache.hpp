#pragma once

#include <iostream>
#include <list>
#include <map>
#include <stdexcept>

class LRU {
private:
    std::list<int> items;
    std::map<int, std::list<int>::iterator> itemMap;

public:
    void access(const int item) {
        if (itemMap.contains(item))
            items.erase(itemMap[item]);

        items.push_front(item);
        itemMap[item] = items.begin();
    }

    int remove() {
        if (items.empty())
            throw std::runtime_error("Cache is empty");

        int lastItem = items.back();
        items.pop_back();
        itemMap.erase(lastItem);
        return lastItem;
    }

    bool contains(const int item) const {
        return itemMap.contains(item);
    }

    int size() const {
        return items.size();
    }

    bool empty() const {
        return items.empty();
    }

    void print() const {
        for (auto it = items.begin(); it != items.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};
