#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

struct StudentInfo {
    std::string first_name;
    std::string last_name;
    std::string email;
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

// Function to read data from "StudentData_Emails.txt"
void readStudentDataEmails(const std::string& filename, std::vector<StudentInfo>& students2) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        StudentInfo student2;

        // Parsing the line (format: last_name, first_name, email)
        std::getline(ss, student2.last_name, ',');
        std::getline(ss, student2.first_name, ',');
        std::getline(ss, student2.email, ',');

        // Add student to the vector
        students2.push_back(student2);
    }

    infile.close();
}

// Function to print student data from "StudentData_Emails.txt"
void printStudents(const std::vector<StudentInfo>& students2) {
    for (const auto& student : students2) {
        std::cout << student.first_name << " " << student.last_name << " - " << student.email << std::endl;
    }
}

int main() {
    std::vector<STUDENT_DATA> students;

    // Call the function to read data from "StudentData.txt"
    readStudentData("StudentData.txt", students);

    // Check if the code is running in Pre-Release or Standard mode
#ifdef PRE_RELEASE
    std::cout << "Running Pre-Release Version" << std::endl;
#else
    std::cout << "Running Standard Version" << std::endl;
#endif

    // Print all student information in debug mode
#ifdef _DEBUG
    for (const auto& student : students) {
        std::cout << student.firstName << " " << student.lastName << std::endl;
    }
#endif

    // Pre-release code to handle reading emails
#ifdef PRE_RELEASE
    std::vector<StudentInfo> students2;
    readStudentDataEmails("StudentData_Emails.txt", students2);
    printStudents(students2);
#endif

    return 0;
}
