#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <ctime>

class NotANumber : public std::domain_error {
public:
    NotANumber(const std::string& msg) : std::domain_error(msg) {}
};

class NegativeNumber : public std::domain_error {
public:
    NegativeNumber(const std::string& msg) : std::domain_error(msg) {}
};

class OddNumber : public std::domain_error {
public:
    OddNumber(const std::string& msg) : std::domain_error(msg) {}
};

class CurveBall : public std::domain_error {
public:
    CurveBall(const std::string& msg) : std::domain_error(msg) {}
};

int readEvenNumber() {
    if (rand() % 4 == 0) {
        throw CurveBall("CurveBall: Something odd happened!");
    }

    int num;
    std::cout << "Enter an even number: ";
    std::cin >> num;

    if (std::cin.fail()) {
        std::cin.clear();
        std::string line;
        std::getline(std::cin, line);
        throw NotANumber("NotANumber: " + line + " is not a number.");
    }

    if (num < 0) 
        throw NegativeNumber("NegativeNumber: " + std::to_string(num) + " is a negative number.");

    if (num % 2 != 0)
        throw OddNumber("OddNumber: " + std::to_string(num) + " is an odd number.");
    
    return num;
}

int main() {
    srand(time(0));
    while (true) {
        try {
            int num = readEvenNumber();
            std::cout << "You entered: " << num << std::endl;
            break;
        } 
        catch (const std::domain_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        } 
        catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
            break;
        }
    }

    return 0;
}