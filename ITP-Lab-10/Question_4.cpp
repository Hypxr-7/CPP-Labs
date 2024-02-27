#include <iostream>

int findMax(int arr[], int n);

int main() {
    int array[] = {3, 7, 1, 9, 5};
    std::cout << "Maximum element: " << findMax(array, std::size(array)) << std::endl;

    return 0;
}

int findMax(int arr[], int n) {
    if (n == 0)
        return -2147483648;
    int m = findMax(arr, n - 1);
    return (m > arr[n - 1]) ? m : arr[n - 1];
}
