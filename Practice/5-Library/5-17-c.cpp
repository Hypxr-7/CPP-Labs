#include <iostream>
#include <cassert>
#include <memory>

class Counter {
public:
    Counter(int i = 0) : p_(new int(i)) { }
    ~Counter() = default;

    Counter(Counter&& c) : p_(std::move(c.p_)) { }
    Counter(const Counter& c) : p_(new int(*(c.p_))) { }

    Counter& operator=(Counter&& c) {
        if (this != &c) {
            p_ = std::move(c.p_);
        }
        return *this;
    }

    Counter& operator=(const Counter& c) {
        if (this != &c) {
            p_.reset(new int(*(c.p_)));
        }
        return *this;
    }

    int getCount() const {
        assert(p_);
        return *p_;
    }

    Counter& operator++() {
        assert(p_);
        ++(*p_);
        return *this;
    }

private:
    std::unique_ptr<int> p_; // pointer to counter value
};

int main() {
    Counter a(0);
    Counter b(std::move(a));
    Counter c(b);
    c = std::move(b);
    b = ++c;
    a = ++c;
    std::cout << a.getCount() << '\n';
    std::cout << b.getCount() << '\n';
    std::cout << c.getCount() << '\n';
}