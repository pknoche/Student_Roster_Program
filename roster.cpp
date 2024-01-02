#include <iostream>
#include <string>
#include <cmath> // included in order to allow for rounding of average days per course
using namespace std;

#include "roster.h"


Roster::Roster() {}  // default constructor

Roster::~Roster() {  // destructor loops through and deletes all student objects
    cout << endl;    // and changes pointers in classRosterArray to nullptr
    for (int i = 0; i < numStudents; i++) {
        cout << "Destructor called for student " << classRosterArray[i]->GetStudentID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
void Roster::Parse(string dataString) {    // puts strings between commas in input
    size_t rhs = dataString.find(",");     // into corresponding variables and calls Add method
    string studentID = dataString.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    string firstName = dataString.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    string lastName = dataString.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    string emailAddress = dataString.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    int age = stoi(dataString.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    int daysInCourse1 = stoi(dataString.substr(lhs, rhs - lhs)); // stoi converts string to integer
    
    lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    int daysInCourse2 = stoi(dataString.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    int daysInCourse3 = stoi(dataString.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = dataString.find(",", lhs);
    string degreeProgramString = dataString.substr(lhs, rhs - lhs);
    
    DegreeProgram degreeProgram = DegreeProgram::UNSPECIFIED; //
    if (degreeProgramString == "SECURITY")                    //
        degreeProgram = DegreeProgram::SECURITY;              //
    else if (degreeProgramString == "NETWORK")                // converts string to enum DegreeProgram
        degreeProgram = DegreeProgram::NETWORK;               //
    else if (degreeProgramString == "SOFTWARE")               //
        degreeProgram = DegreeProgram::SOFTWARE;              //
    
    // call Add method to add parsed input to new student object
    Add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    // put daysInCourse variables into array to pass to student constructor
    int daysPerCourse[Student::daysPerCourseArraySize] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    //dynamically creates new Student object and increments lastIndex variable
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysPerCourse, degreeProgram);
}
void Roster::Remove(string studentID) {
    cout << "Removing " << studentID << endl;
    bool successful = false;
    for (int i = 0; (i <= lastIndex) && (successful == false); i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {   // If ID specified to remove is found, copies
            successful = true;                                    // corresponding student pointer to temporary
            Student* temp = classRosterArray[i];                  // variable, swaps following pointers back
            for (i = i; i < numStudents; i++)                     // one index, copies temporary variable to
                classRosterArray[i] = classRosterArray[i+1];      // last index in array, then decrements lastIndex
            classRosterArray[numStudents - 1] = temp;             // variable so that removed student is not
        }                                                         // printed when PrintAll method is called.
    }
    if (successful) {
        cout << "Successfully removed student with the ID: " << studentID << endl;
        lastIndex--;
    }
    else
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    
    cout << endl;
}
void Roster::PrintAll() {   // calls Student::Print method for students that have not been removed
    cout << endl << "Displaying all students:" << endl;
    for (int i = 0; i <= lastIndex; i++)
        classRosterArray[i]->Print();
    
    cout << endl << endl;
}
void Roster::PrintAverageDaysInCourse(string studentID) {
    int studentIndex = -1;
    for (int i = 0; i <= lastIndex; i++) {                           // Calls GetStudentID and compares to return value
        string searchID = classRosterArray[i]->GetStudentID();       // until match is found. When match is found, sets
        if (studentID == searchID) {                                 // index to where matched student object pointer is
            studentIndex = i;                                        // stored and uses that to call GetDaysPerCourse
            break;
        }
    }
    if (studentIndex != -1) {
        const int* daysPerCourse = classRosterArray[studentIndex]->GetDaysPerCourse();
        int sum = 0;
        for (int i = 0; i < Student::daysPerCourseArraySize; i++)
            sum += daysPerCourse[i];
        cout << "Student ID: " << studentID << ", average days in course is: " << round(sum / static_cast<double>(Student::daysPerCourseArraySize)) << endl;
    }
    else {cout << "ID not found" << endl;}
    
    cout << endl;
}
void Roster::PrintInvalidEmails() {
    cout << endl << "Displaying invalid emails:" << endl << endl;
    for (int i = 0; i <= lastIndex; i++) {  //checks for presence of space or absence of '@' or '.'
        string email = classRosterArray[i]->GetEmailAddress();
        if ((email.find(' ') != string::npos) || (email.find('@') == string::npos) || (email.find('.') == string::npos))
            cout << email << " - is invalid." << endl;
    }
    cout << endl << endl;
}
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    cout << endl << "Showing students in degree program: " << degreeProgramStrings[(int)degreeProgram] << endl << endl;
    for (int i = 0; i <= lastIndex; i++) {
        DegreeProgram searchParameter;
        searchParameter = classRosterArray[i]->GetDegreeProgram();
        if (searchParameter == degreeProgram)
            classRosterArray[i]->Print();
    }
    cout << endl << endl;
}
Student** Roster::GetStudents() {
    return classRosterArray;
}

