#include <cassert>
#include <iostream>
#include <string>

#include "OrderedArrayST.hpp"

void testOrderedArrayST();

int main() {
    testOrderedArrayST();

    std::cout << "All tests passed\n";

    return 0;
}

void testOrderedArrayST() {
    OrderedArrayST<std::string> st;

    st.add("hello");
    st.add("world");
    st.add("bye");
    st.add("array");
    st.add("symbol");
    st.add("table");

    assert(st.contains("symbol"));
    assert(!st.contains("x"));

    assert(st.ceiling("cat") == "hello");
    assert(st.ceiling("symbols") == "table");

    assert(st.rank("bye") == 1);
    assert(st.rank("cat") == 2);
    assert(st.rank("z") == 6);
    assert(st.rank("p") == 3);

    assert(st.select(0) == "array");
    assert(st.select(2) == "hello");

    assert(st.min() == "array");

    st.deleteKey("array");
    assert(!st.contains("array"));
}