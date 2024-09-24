#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

// Function to read data from "StudentData.txt"
void readStudentData(const std::string& filename, std::vector<STUDENT_DATA>& students) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
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
}

int main() {
    std::vector<STUDENT_DATA> students;

    // Call the function to read data from "StudentData.txt"
    readStudentData("StudentData.txt", students);

#ifdef _DEBUG
    std::cout << "Debug Mode: Printing all student information:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.firstName << " " << student.lastName << std::endl;
    }
#endif

    return 0;
}
