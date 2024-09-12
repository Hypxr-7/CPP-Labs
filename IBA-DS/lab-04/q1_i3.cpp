#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
#include <chrono>

class MergeX {
public:
    static void sort(std::vector<std::string>& a) {
        std::vector<std::string> aux(a);
        sort(aux, a, 0, a.size() - 1);
        assert(isSorted(a));
    }

private:
    static const int CUTOFF = 7;

    static void merge(std::vector<std::string>& src, std::vector<std::string>& dst, int lo, int mid, int hi) {
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; ++k) {
            if (i > mid) {
                dst[k] = src[j++];
            } else if (j > hi) {
                dst[k] = src[i++];
            } else if (src[j] < src[i]) {
                dst[k] = src[j++];
            } else {
                dst[k] = src[i++];
            }
        }
    }

    static void sort(std::vector<std::string>& src, std::vector<std::string>& dst, int lo, int hi) {
        if (hi <= lo + CUTOFF) {
            insertionSort(dst, lo, hi);
            return;
        }
        int mid = lo + (hi - lo) / 2;
        sort(dst, src, lo, mid);
        sort(dst, src, mid + 1, hi);
        if (src[mid + 1] >= src[mid]) {
            std::copy(src.begin() + lo, src.begin() + hi + 1, dst.begin() + lo);
            return;
        }
        merge(src, dst, lo, mid, hi);
    }

    static void insertionSort(std::vector<std::string>& a, int lo, int hi) {
        for (int i = lo; i <= hi; ++i) {
            for (int j = i; j > lo && a[j] < a[j - 1]; --j) {
                std::swap(a[j], a[j - 1]);
            }
        }
    }

    static bool isSorted(const std::vector<std::string>& a, int lo = 0, int hi = -1) {
        if (hi == -1) hi = a.size() - 1;
        for (int i = lo + 1; i <= hi; ++i) {
            if (a[i] < a[i - 1]) return false;
        }
        return true;
    }

    static void show(const std::vector<std::string>& a) {
        for (const auto& s : a) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
};

void merge(std::vector<std::string>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<std::string> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void normalMergeSort(std::vector<std::string>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    normalMergeSort(arr, l, m);
    normalMergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

std::vector<std::string> generateRandomStrings(int n, int stringLength = 5) {
    std::vector<std::string> randomStrings;
    std::string charset = "abcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, charset.size() - 1);

    for (int i = 0; i < n; ++i) {
        std::string randomString;
        for (int j = 0; j < stringLength; ++j) {
            randomString += charset[dist(generator)];
        }
        randomStrings.push_back(randomString);
    }

    return randomStrings;
}

int main() {
    int arraySize = 100000;

    std::vector<std::string> arr1 = generateRandomStrings(arraySize);
    std::vector<std::string> arr2 = arr1;

    auto start = std::chrono::high_resolution_clock::now();
    MergeX::sort(arr1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeXDuration = end - start;
    std::cout << "MergeX Sort time: " << mergeXDuration.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    normalMergeSort(arr2, 0, arr2.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> normalMergeDuration = end - start;
    std::cout << "Normal Merge Sort time: " << normalMergeDuration.count() << " seconds\n";


    // for (int i = 0; i < 10000; i += 100) std::cout << arr1[i] << ' ';
    return 0;
}
