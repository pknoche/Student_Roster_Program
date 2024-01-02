#ifndef roster_h
#define roster_h

#include "student.h"

class Roster {
    
    public:
        Roster();  // Constructor
    
        ~Roster(); // Destructor

        void Parse(string dataString);  // parses comma delimited input into individual data fields then calls Add method
    
        void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); // adds student to roster
    
        void Remove(string studentID); // removes student from roster
    
        void PrintAll(); // prints all students that have not been removed
    
        void PrintAverageDaysInCourse(string studentID); // prints student's average number of days in three courses
    
        void PrintInvalidEmails(); // prints invalid student emails
    
        void PrintByDegreeProgram(DegreeProgram degreeProgram); // prints students in specified degree program
    
        Student** GetStudents(); // Gets pointer to student objects. ** required because pointer returned is itself a pointer to the student objects and must be dereferenced twice. Used in main to call PrintAverageDaysInCourse for all students.

      
    private:
        int lastIndex = -1; // keeps track of number of students to display.
                            // Initialized with -1 since index[0] will be
                            // first student and -1 means no students
        const static int numStudents = 5; // size of array needed to store inputs
        Student* classRosterArray[numStudents]; // array of pointers to store students
};


#endif /* roster_h */
