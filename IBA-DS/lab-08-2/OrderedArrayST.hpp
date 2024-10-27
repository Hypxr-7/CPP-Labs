#pragma once

#include <vector>
#include <stdexcept>

template<typename Key> 
class OrderedArrayST {
private:
    std::vector<Key> m_keys;
    int n;

    void resize(const int size) {
        m_keys.resize(size);
    }

    int binarySearch(const Key& key) const {
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (key > m_keys[mid]) lo = mid + 1;
            else if (key < m_keys[mid]) hi = mid - 1;
            else return mid; 
        }

        return -1;
    }

public:
    OrderedArrayST() : m_keys(1), n(0) {}

    void add(const Key& key) {
        if (n == m_keys.size()) resize(2*n);

        if (contains(key)) return;
        if (key == Key{}) return;

        int insertPosn = 0;
        while (insertPosn < n && key > m_keys[insertPosn]) ++insertPosn;

        for (int i = n; i > insertPosn; --i) m_keys[i] = m_keys[i-1];
        m_keys[insertPosn] = key;
        ++n;
    }

    bool contains(const Key& key) const {
        return binarySearch(key) != -1;
    }

    Key ceiling(const Key& key) const {
        if (key > m_keys[n-1]) throw std::invalid_argument("argument to ceiling() is too large");
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (m_keys[mid] < key) lo = mid + 1;
            else hi = mid - 1;
        }

        if (lo < n) return m_keys[lo];

        throw std::invalid_argument("No ceiling found");
    }

    int rank(const Key& key) const {
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (m_keys[mid] < key) lo = mid + 1;
            else if (m_keys[mid] > key) hi = mid - 1;
            else return mid;
        }

        return lo;
    }

    Key select(const int i) const {
        if (i < 0 || i >= n) throw std::out_of_range("argument to select() is out of range");

        return m_keys[i];
    }

    Key min() const {
        if (n == 0) throw std::runtime_error("symbol table is empty");

        return m_keys[0];
    }

    void deleteKey(const Key& key) {
        int pos = binarySearch(key);
        if (pos == -1) return;

        for (int i = pos; i < n - 1; ++i)
            m_keys[i] = m_keys[i + 1];
        --n;

        if (n > 0 && n == m_keys.size() / 4) resize(m_keys.size() / 2);
    }
};