#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    
    std::cout << "Enter you age: ";
    int age;
    std::cin >> age;
    
    std::cout << "Hello " << name << ", you are " << age << " years old.";
}