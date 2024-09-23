#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <algorithm>

using std::vector, std::cout;

template<typename T>
int partition(vector<T>& a, int lo, int hi) {
    int i = lo, j = hi+1;
    while (true) {

        while (a[++i] < a[lo])
            if (i == hi) break;

        while (a[lo] < a[--j])
            if (j == lo) break;
       
        if (i >= j) break;
        std::swap(a[i], a[j]);
   }

   std::swap(a[lo], a[j]);
   return j;
} 

template<typename T>
void quicksort(vector<T>& a, int lo, int hi) {
      if (hi <= lo) return;
      int j = partition(a, lo, hi);
      quicksort(a, lo, j-1);
      quicksort(a, j+1, hi);
}

template<typename T>
void quicksort(vector<T>& a) {
      std::shuffle(a.begin(), a.end(), std::default_random_engine(std::random_device{}()));
      quicksort(a, 0, a.size() - 1);
}

int main() {
    std::mt19937 gen(std::random_device{}());
    
    const int N = 50;
    std::vector<int> a(N);
    for(int i=0; i<N; i++)
        a[i] = gen();
        
    quicksort(a);

    for(const auto& x: a)
        std::cout << std::setw(13) << x << "\n";
}
