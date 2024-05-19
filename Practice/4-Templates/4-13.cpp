#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>

template <class T>
void do_work(){

    auto print_container = [](std::ostream& os, const T& container){
        for (const auto& element : container)
            os << element << ' ';
        os << '\n';
    };

    auto prefix_increment = [](auto& x){ ++x; };

    T v{0, 1, 2, 3, 4, 5, 6, 7};

    print_container(std::cout, v);

    std::for_each(v.begin(), v.end(), prefix_increment);

    print_container(std::cout, v);

}

int main(){
    do_work<std::vector<int>>();
    do_work<std::deque<int>>();
    do_work<std::list<int>>();
}