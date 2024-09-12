#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

void ShellSort(vector<int>& arr) {
  int h, i, j;
  int tmp;

    vector<int> increments = {3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1}; 
  //   0.0464 seconds 

  // vector<int> increments = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1};  
  //   0.124 seconds

  // vector<int> increments = {9841, 3280, 1093, 364, 121, 40, 13, 4, 1};  
  // 0.0321 seconds

  int n = arr.size();
  for (auto h : increments) {
    for (i = h; i < n; i++) {
      tmp = arr[i];
      for (j = i; j >= h && arr[j - h] > tmp; j -= h) arr[j] = arr[j - h];
      arr[j] = tmp;
    }
  }
}

int main() {
  int n = 100'000;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  //   for (auto e : arr) cout << e << ' ';
  //   cout << '\n';

  //   ShellSort(arr);

  //   for (auto e : arr) cout << e << ' ';
  //   cout << '\n';

  auto start = chrono::high_resolution_clock::now();
  ShellSort(arr);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> original_duration = end - start;
  cout << "Time Taken: " << original_duration.count() << " seconds" << endl;

  return 0;
}