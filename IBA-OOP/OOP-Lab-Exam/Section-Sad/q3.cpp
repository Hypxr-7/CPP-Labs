#include <string>
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <random>

using std::cout, std::string, std::vector;

struct Student {
    string name;
    bool male;
    double cgpa;
};

// Your implementation of top_student function goes here
// Define lambda functions and use STL algorithms to find the top male and female students and print their names
void top_student(const vector<Student>& students) {
    vector<Student> males;
    vector<Student> females;

    auto isMale = [](const Student& student){ return student.male; };
    auto isFemale = [](const Student& student){ return !student.male; };
    auto compare = [](const Student& student1, const Student& student2){ return student1.cgpa < student2.cgpa; };

    std::copy_if(students.begin(), students.end(), std::back_inserter(males), isMale);
    std::copy_if(students.begin(), students.end(), std::back_inserter(females), isFemale);

    auto topMale = std::ranges::max_element(males, compare);
    auto topFemale = std::ranges::max_element(females, compare);

    std::cout << "Top Male: " << topMale->name << "  CGPA: " << topMale->cgpa << '\n';
    std::cout << "Top Female: " << topFemale->name << "  CGPA: " << topFemale->cgpa << '\n';
}



int main() {
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> cgpa_dist(2.0, 4.0); // CGPA between 2.0 and 4.0
    std::bernoulli_distribution gender(0.5);
    const int n = 10;
    std::uniform_int_distribution<size_t> names_dist(0, n - 1);

    vector<string> male_names = {
            "Ali", "Hassan", "Amir", "Zubair", "Saad", "Bilal", "Saeed", "Usman", "Fahad", "Shaheer"
    };
    vector<string> female_names = {
            "Aisha", "Fatima", "Zainab", "Maryam", "Sana", "Hira", "Sadia", "Rabia", "Hina", "Nadia"
    };

    const int m = 100;
    // create random data of m students
    vector<Student> students(m);
    for (int i = 0; i < m; i++) {
        int r = names_dist(gen);
        bool g = gender(gen);
        students[i].name = (g?male_names:female_names)[r] + std::to_string(i);
        students[i].male = g;
        students[i].cgpa = cgpa_dist(gen);
    }

    // print the students data
    for(auto& student: students)
        cout << student.name << " " << student.cgpa << '\n';

    top_student(students);
}
