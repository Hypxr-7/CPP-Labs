#include <cassert>
#include <iostream>
#include <string>

#include "RedBlackBST.hpp"

class MutableString {
private:
    RedBlackBST<double, char> bst;

public:
    MutableString(std::string s = "") {
        if (s.empty()) return;
        for (int i = 0; i < s.length(); ++i) {
            bst.put(static_cast<double>(i), s[i]);
        }
    }

    char get(const int i) const {
        return bst.get(bst.select(i));
    }

    void insert(const int i, const char c) {
        if (bst.isEmpty()) {
            bst.put(0.0, c);
            return;
        }

        double ub = bst.select(i);
        if (bst.min() == ub) {
            bst.put(ub - 1.0, c);
            return;
        }

        double lb = bst.select(i - 1);
        double mid = (lb + ub) / 2.0;
        bst.put(mid, c);
    }

    void remove(const int i) {
        bst.deleteKey(bst.select(i));
    }

    void print() const {
        for (const auto& key : bst.keys())
            std::cout << bst.get(key);
        std::cout << '\n';
    }
};

void testInitialization() {
    MutableString ms("foobarqux");
    std::string expected = "foobarqux";
    for (int i = 0; i < expected.length(); ++i) {
        assert(ms.get(i) == expected[i]);
    }
}

void testInsert() {
    MutableString ms("foobarqux");
    ms.insert(3, 'x');  // fooxbarqux
    std::string expected = "fooxbarqux";
    for (int i = 0; i < expected.length(); ++i) {
        assert(ms.get(i) == expected[i]);
    }
}

void testRemove() {
    MutableString ms("foobarqux");
    ms.insert(3, 'x');  // fooxbarqux
    ms.remove(3);       // removes second x in foox
    std::string expected = "foobarqux";
    for (int i = 0; i < expected.length(); ++i) {
        assert(ms.get(i) == expected[i]);
    }
}

void testGet() {
    MutableString ms("foobarqux");
    assert(ms.get(4) == 'a');  // first letter is in posn 0
}

int main() {
    testInitialization();
    testInsert();
    testRemove();
    testGet();
    std::cout << "All tests passed!" << std::endl;

    return 0;
}