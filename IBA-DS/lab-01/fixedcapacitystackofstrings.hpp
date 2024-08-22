#include <string>
using std::string;

class FixedCapacityStackOfStrings {
    private:
        string* s;
        int N = 0;
    public:
        FixedCapacityStackOfStrings(int capacity) {
            s = new std::string[capacity];
        }
        ~FixedCapacityStackOfStrings() {
            delete[] s;
        }
        bool empty() {
            return N == 0;
        }
        void push(const string& item) {
            s[N++] = item;
        }
        std::string pop() {
            return std::move(s[--N]);
        }
};
