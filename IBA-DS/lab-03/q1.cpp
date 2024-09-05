#include <iostream>
#include <random>

class EggDrop {
public:
    EggDrop(int N) : F(std::random_device()() % N + 1) {}

    bool operator()(int x) {
        if (x >= F)
            return true;
        return false;
    }

private:
    int F;
};

int main() {
    int N = 10000;
    EggDrop eggdrop(N);

    int lo = 1, hi = 1;
    while (!eggdrop(hi)) {
        hi *= 2;
        lo = hi / 2;
    }

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (eggdrop(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    std::cout << "The value of F is " << lo << std::endl;

    return 0;
}