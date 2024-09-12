#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid,
                  int right) {
  int i = left;
  int j = mid + 1;
  int k = left;
  int inv_count = 0;

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count += (mid - i + 1);  // elements from arr[i] to arr[mid] will form inversions with arr[j]
    }
  }

  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  while (j <= right) {
    temp[k++] = arr[j++];
  }

  for (int i = left; i <= right; i++) {
    arr[i] = temp[i];
  }

  return inv_count;
}

int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left,
                      int right) {
  int inv_count = 0;
  if (left < right) {
    int mid = left + (right - left) / 2;

    inv_count += mergeSortAndCount(arr, temp, left, mid);
    inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
    inv_count += mergeAndCount(arr, temp, left, mid, right);
  }
  return inv_count;
}

int countInversions(vector<int>& arr) {
  vector<int> temp(arr.size());
  return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

int main() {
  vector<int> arr = {2, 3, 8, 6, 1, 4};
  int inv_count = countInversions(arr);
  cout << "Number of inversions: " << inv_count << endl;
  return 0;
}
