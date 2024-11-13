#include <cassert>
#include <iostream>

#include "Svector.hpp"

void test_set_get() {
    Svector vec;
    vec.set(1, 3.5);
    assert(vec.get(1) == 3.5);
    vec.set(1, 0.0);
    assert(vec.get(1) == 0.0);
}

void test_dot() {
    Svector vec1, vec2;
    vec1.set(1, 2.0);
    vec1.set(2, 3.0);
    vec2.set(1, 4.0);
    vec2.set(2, 5.0);
    assert(vec1.dot(vec2) == 23.0);
}

void test_norm() {
    Svector vec;
    vec.set(1, 3.0);
    vec.set(2, 4.0);
    assert(vec.norm() == 25.0);
}

void test_add() {
    Svector vec1, vec2;
    vec1.set(1, 1.0);
    vec1.set(2, 2.0);
    vec2.set(2, 3.0);
    vec2.set(3, 4.0);
    Svector result = vec1.add(vec2);
    assert(result.get(1) == 1.0);
    assert(result.get(2) == 5.0);
    assert(result.get(3) == 4.0);
}

void test_scale() {
    Svector vec;
    vec.set(1, 1.0);
    vec.set(2, 2.0);
    vec.scale(2.0);
    assert(vec.get(1) == 3.0);
    assert(vec.get(2) == 4.0);
}

int main() {
    test_set_get();
    test_dot();
    test_norm();
    test_add();
    test_scale();

    std::cout << "All tests passed\n";

    return 0;
}