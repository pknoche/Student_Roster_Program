#include <iostream>
#include <string>
using namespace std;

#include "student.h"


//Constructors
Student::Student() {
    this->studentID = "UNSPECIFIED";
    this->firstName = "UNSPECIFIED";
    this->lastName = "UNSPECIFIED";
    this->emailAddress = "UNSPECIFIED";
    this->age = -1;
    for (int i = 0; i < daysPerCourseArraySize; i++)      // sets each element in daysPerCourse to default value
        this->daysPerCourse[i] = -1;
    this->degreeProgram = DegreeProgram::UNSPECIFIED;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysPerCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < daysPerCourseArraySize; i++)     // sets each element in daysPerCourse
        this->daysPerCourse[i] = daysPerCourse[i];
    this->degreeProgram = degreeProgram;
}

//Destructor:
Student::~Student() {cout << "Student Destroyed" << endl << endl;}

//Setters:
void Student::SetStudentID(int studentID) {
    this->studentID = studentID;
}
void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}
void Student::SetEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::SetAge(int age) {
    this->age = age;
}
void Student::SetDaysPerCourse(const int daysPerCourse[]) {
    for (int i = 0; i < daysPerCourseArraySize; i++)
        this->daysPerCourse[i] = daysPerCourse[i];
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//Getters:
string Student::GetStudentID() const {
    return this->studentID;
}
string Student::GetFirstName() const {
    return this->firstName;
}
string Student::GetLastName() const {
    return this->lastName;
}
string Student::GetEmailAddress() const {
    return this->emailAddress;
}
int Student::GetAge() const {
    return this->age;
}
 const int* Student::GetDaysPerCourse() const {
    return this->daysPerCourse;
}
DegreeProgram Student::GetDegreeProgram() const {
    return this->degreeProgram;
}
void Student::Print() {
    cout << this->studentID << '\t';
    cout << this->firstName << '\t';
    cout << this->lastName << '\t';
    cout << this->age << '\t';
    cout << "{";
    for (int i = 0; i < daysPerCourseArraySize; i++) {
        cout << this->daysPerCourse[i];
        if (i < daysPerCourseArraySize - 1) // prevents comma from being displayed after last element
            cout << ",";
    }
    cout << "}" << '\t';
    cout << degreeProgramStrings[(int)this->degreeProgram]; // cast enum type to int and use that to return
                                                            // corresponding degree program string from
                                                            // degreeProgramStrings array
    cout << endl;
}
