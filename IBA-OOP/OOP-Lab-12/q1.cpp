#include <iostream>
#include "Stack.h"


int main() {
    Stack s;

    std::cout << "Pushing values 'A', 'B', 'C' in stack\n";

    s.push('A');
    s.push('B');
    s.push('C');

    std::cout << "Top: " << s.top() << '\n';

    std::cout << "Empty: " << std::boolalpha << s.empty() << '\n';

    std::cout << "Printing: ";
    s.print();

    std::cout << "Popping: " << s.pop() << '\n';
    std::cout << "Popping: " << s.pop() << '\n';
    std::cout << "Popping: " << s.pop() << '\n';

    std::cout << "Empty: " << std::boolalpha << s.empty() << '\n';

    return 0;
}
