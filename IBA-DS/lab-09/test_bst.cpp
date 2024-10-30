#include <cassert>
#include <iostream>
#include <string>
#include "bst.hpp"

void testBST();

int main() {
    testBST();

    std::cout << "All tests passed\n";

    return 0;
}

void testBST() {
    BST<int , std::string> bst;

    bst.put(1, "aa");
    bst.put(2, "ab");
    bst.put(3, "ac");
    bst.put(4, "ad");
    bst.put(5, "ae");

    assert(bst.height_recursive() == 4 && bst.height_iterative() == 4);
    assert(bst.size() == 5);

    bst.put(-1, "aa");

    assert(bst.height_recursive() == 4 && bst.height_iterative() == 4);   
    assert(bst.size_iterative() == 6);

    assert((bst.keys(2, 4) == std::vector<int>{2, 3, 4}));

    assert(bst.max() == 5);
    assert(bst.min() == -1);

    bst.deleteMax();
    assert(bst.max() == 4);

    bst.removeMin();
    assert(bst.min() == 1);

    assert(bst.floor(1) == 1);
    assert(bst.ceiling(2) == 2);

    assert(bst.select(2) == 3);

    assert(bst.rank(3) == 2);

    bst.test();

    assert(bst.isRankConsistent());
}