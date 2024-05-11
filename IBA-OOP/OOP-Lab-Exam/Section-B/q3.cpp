#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
#include <cctype>

struct Student {
    std::string name;
    int id;
    double gpa;
};

struct SortByGpaAndName {
    bool operator()(const Student& s1, const Student& s2) const {
        if (s1.gpa != s2.gpa) return s1.gpa > s2.gpa;
        return s1.name < s2.name;
    }
};

int main() {
    std::vector<Student> students = {
            {"Alice", 1001, 3.5},
            {"Bob", 1002, 3.5},
            {"Charlie", 1003, 3.7},
            {"David", 1004, 3.9},
            {"Eve", 1005, 3.8},
            {"Frank", 1006, 3.6}
    };

    std::ranges::sort(students, SortByGpaAndName{});

    auto longNamesCount = std::ranges::count_if(students, [](const Student& s) { return s.name.length() > 8; });

    auto myFunc = [](const Student& s) {
        std::string newStr;
        std::ranges::transform(s.name, std::back_inserter(newStr), ::toupper);
        return newStr;
    };

    // using names instead of IDs
    using namespace std::views;
    auto uppercase = students | transform(myFunc);

    std::cout << "Sorted Student Records:" << std::endl;
    for (const auto& student : students)
        std::cout << "Name: " << student.name << ", ID: " << student.id << ", GPA: " << student.gpa << std::endl;

    std::cout << "Number of students with names longer than 8 characters: " << longNamesCount << std::endl;

    std::cout << "Transformed Student Names to Uppercase:" << std::endl;
    for (const auto& name : uppercase)
        std::cout << name << std::endl;

    return 0;
}
