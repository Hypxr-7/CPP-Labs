#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

template <typename T>
void sink(std::vector<T>& pq, int k, int n) {
  while (2 * k <= n) {
    int j = 2 * k;
    if (j < n && pq[j - 1] < pq[j]) j++;
    if (!(pq[k - 1] < pq[j - 1])) break;
    std::swap(pq[k - 1], pq[j - 1]);
    k = j;
  }
}

template <typename T>
void heapsort(std::vector<T>& pq) {
  time_t startMain = clock();
  time_t startCon = clock();

  int n = pq.size();

  // heapify phase
  for (int k = n / 2; k >= 1; k--) sink(pq, k, n);

  time_t endCon = clock();

  // sort down phase
  int k = n;
  while (k > 1) {
    std::swap(pq[0], pq[k - 1]);
    k--;
    sink(pq, 1, k);
  }

  time_t endMain = clock();

  double perc = (static_cast<double>(endCon - startCon) /
                 static_cast<double>(endMain - startMain)) *
                100;
  std::cout << "Time Taken by Constructor (%): " << perc << std::endl;
}

int main() {
  std::vector<int> vec(1'000'000'000);
  std::generate(vec.begin(), vec.end(), std::mt19937(std::random_device{}()));
  heapsort(vec);
  return 0;
}
