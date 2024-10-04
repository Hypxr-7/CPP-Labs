#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <cassert>

template <typename T>
int sink(std::vector<T>& pq, int k, int n) {
    static int count = 0;
    while (true) {

        int left = 3 * k + 1;
        int mid = 3 * k + 2;
        int right = 3 * k + 3;

        int largest = k;
        if (left < n && pq[largest] < pq[left]) {
            largest = left;
            ++count;
        }
        if (mid < n && pq[largest] < pq[mid]) {
            largest = mid;
            ++count;
        }
        if (right < n && pq[largest] < pq[right]) {
            largest = right;
            ++count;
        }
        if (largest != k) { 
            std::swap(pq[k], pq[largest]);
            k = largest;
            continue;
        }
        break;
    }
    return count;
}

template <typename T>
void heapsort(std::vector<T>& pq) {
    int n = pq.size();
    int count = 0;

    // heapify phase
    for (int k = (n - 2) / 3; k >= 0; k--) 
        count += sink(pq, k, n);

    // sort down phase
    int k = n;
    while (k > 1) {
        std::swap(pq[0], pq[k - 1]);
        k--;
        count += sink(pq, 0, k);
    }
    std::cout << "Compares: " << count << std::endl;
}

int main() {
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), std::mt19937(std::random_device{}()));

    // std::vector<int> vec = {1, 5, 6, 7, 3, 8, 5};

    heapsort(vec);
    assert(std::is_sorted(vec.cbegin(), vec.cend()));

    return 0;
}