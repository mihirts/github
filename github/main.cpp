#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

int main() {
    std::vector<STUDENT_DATA> students;
    std::ifstream inputFile("StudentData.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string firstName, lastName;

        if (std::getline(ss, firstName, ',') && std::getline(ss, lastName)) {
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
    }

    inputFile.close();

    // Print all student information in debug mode
#ifdef _DEBUG
    for (const auto& student : students) {
        std::cout << student.firstName << " " << student.lastName << std::endl;
    }
#endif
 
    

    return 0;
}
