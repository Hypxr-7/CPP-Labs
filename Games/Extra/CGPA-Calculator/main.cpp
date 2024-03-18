#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

double GradeToGPA(std::string grade) {
    if (grade == "A") return 4.0;
    if (grade == "A-") return 3.67;
    if (grade == "B+") return 3.33;
    if (grade == "B") return 3.0;
    if (grade == "B-") return 2.67;
    if (grade == "C+") return 2.33;
    if (grade == "C") return 2.0;
    if (grade == "C-") return 1.67;
    if (grade == "F") return 0;
    return -1;
}

int main(){
    int totalCredits = 0;
    double totalGPA = 0;

    std::ifstream file("grades.csv");
    if (!file.is_open()) {
        std::cout << "Error: File not found" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip the header
    while (std::getline(file, line)) {
        std::string credit, grade;
        std::stringstream ss(line);
        std::getline(ss, grade, ',');
        std::getline(ss, credit, ',');

        double gpa = GradeToGPA(grade);
        if (gpa == -1) {
            std::cout << "Error: Invalid grade" << std::endl;
            return 1;
        }

        totalCredits += stoi(credit);
        totalGPA += gpa * stoi(credit);
    }

    std::cout << "CGPA: " << totalGPA / totalCredits << std::endl;

    return 0;
}