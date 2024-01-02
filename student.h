#ifndef student_h
#define student_h

#include "degree.h"

class Student {

    public:
        const static int daysPerCourseArraySize = 3; // size of array needed to store daysPerCourse
    
        //Constructors:
        Student();
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysPerCourse[], DegreeProgram degreeprogram);
    
        //Destructor:
        ~Student();
        
        //Setters:
        void SetStudentID(int studentID); // sets student ID
        void SetFirstName(string firstName); // sets first name
        void SetLastName(string lastName); // sets last name
        void SetEmailAddress(string emailAddress); // sets email address
        void SetAge(int age); // sets age
        void SetDaysPerCourse(const int daysPerCourse[]); // sets daysPerCourse into array
        void SetDegreeProgram(DegreeProgram degreeProgram); //sets degree program using enum type

        //Getters:
        string GetStudentID() const; // returns student ID
        string GetFirstName() const; // returns first name
        string GetLastName() const; // returns last name
        string GetEmailAddress() const; // returns email address
        int GetAge() const; // returns age
        const int* GetDaysPerCourse() const; // returns pointer to array for number of days taken per course
        DegreeProgram GetDegreeProgram() const; // returns degree program
    
        void Print(); // print individual student
    
    
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysPerCourse[daysPerCourseArraySize];
        DegreeProgram degreeProgram;
};

#endif /* student_h */
