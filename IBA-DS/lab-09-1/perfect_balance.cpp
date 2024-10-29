#include <iostream>
#include <vector>
#include "bst.hpp"

// Function to insert keys into the BST to maintain perfect balance
void insertBalanced(BST<int, char>& bst, const std::vector<int>& keys, int start, int end) {
    if (start > end) return;

    int mid = start + (end - start) / 2;
    bst.put(keys[mid], 'a');

    insertBalanced(bst, keys, start, mid - 1);
    insertBalanced(bst, keys, mid + 1, end);
}

int main() {
    std::vector<int> keys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example keys
    BST<int, char> bst;

    insertBalanced(bst, keys, 0, keys.size() - 1);

    std::cout << "In-order traversal of the balanced BST: ";
    for (const auto e : bst.levelOrder()) std::cout << e << ' ';
    std::cout << '\n';
    std::cout << bst.height_recursive() << '\n';

    return 0;
}