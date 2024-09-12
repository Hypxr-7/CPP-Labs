#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void merge(vector<int>& src, vector<int>& dst, int low, int mid, int high) {
  int i = low, j = mid + 1;

  // If already sorted, avoid merging
  if (src[mid] <= src[j]) {
    for (int k = low; k <= high; k++) {
      dst[k] = src[k];
    }
    return;
  }

  

  for (int k = low; k <= high; k++) {
    if (i > mid)
      dst[k] = src[j++];
    else if (j > high)
      dst[k] = src[i++];
    else if (src[j] < src[i])
      dst[k] = src[j++];
    else
      dst[k] = src[i++];
  }
}

void mergeSort(vector<int>& src, vector<int>& dst, int low, int high,
               int cutoff) {
  if (high <= low) return;

  if (high - low <= cutoff) {
    insertionSort(dst, low, high);
    return;
  }

  int mid = low + (high - low) / 2;

  mergeSort(dst, src, low, mid, cutoff);
  mergeSort(dst, src, mid + 1, high, cutoff);

  merge(src, dst, low, mid, high);
}

void improvedMergeSort(vector<int>& arr, int cutoff) {
  vector<int> aux = arr;
  mergeSort(aux, arr, 0, arr.size() - 1, cutoff);
}

void originalMergeSort(vector<int>& arr, vector<int>& aux, int low, int high) {
  if (high <= low) return;
  int mid = low + (high - low) / 2;
  originalMergeSort(arr, aux, low, mid);
  originalMergeSort(arr, aux, mid + 1, high);
  merge(arr, aux, low, mid, high);
}

void originalMergeSortWrapper(vector<int>& arr) {
  vector<int> aux = arr;
  originalMergeSort(aux, arr, 0, arr.size() - 1);
}

int main() {
  srand(time(nullptr));
  int n = 100000;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 1000000;
  }

  vector<int> arr_copy = arr;

  // Benchmark original merge sort
  auto start = chrono::high_resolution_clock::now();
  originalMergeSortWrapper(arr);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> original_duration = end - start;
  cout << "Original MergeSort: " << original_duration.count() << " seconds"
       << endl;

  // Benchmark improved merge sort
  arr = arr_copy;
  start = chrono::high_resolution_clock::now();
  improvedMergeSort(arr, 10);  // cutoff = 10
  end = chrono::high_resolution_clock::now();
  chrono::duration<double> improved_duration = end - start;
  cout << "Improved MergeSort: " << improved_duration.count() << " seconds"
       << endl;

  for (int i = 0; i < 100000; i += 100) cout << arr[i] << '\n';

  return 0;
}
