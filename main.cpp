//
//  main.cpp
//  Performance Assessment
//
//  Created by Philipp Knoche on 11/11/22.
//

#include <iostream>
#include <string>
using namespace std;

#include "roster.h"


int main() {
    // Print course information
    cout << "C867-Scripting & Programming: Applications" << endl << "Language: C++" << endl << "Student ID: 000000000" << endl << "Name: Philipp Knoche" << endl;
    cout << "------------------------------------------------" << endl;

    
    // Data to input
    const int numStudents = 5;
    const string dataStrings[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Philipp,Knoche,my_email@wgu.edu,27, 7,19,11,SOFTWARE"};
       
    
    Roster classRoster;  // create new roster object
    
    for (int i = 0; i < numStudents; i++)  // iterates through input streams and calls
        classRoster.Parse(dataStrings[i]); // Parse method which parses data and then
                                           // calls Add method to create new student objects
    
    classRoster.PrintAll();
    
    classRoster.PrintInvalidEmails();
                                                                   // loop calls GetStudents method to
    for (int i = 0; i < numStudents; i++) {                        // return pointer to student object,
        string ID = classRoster.GetStudents()[i]->GetStudentID();  // which is then used to call
        classRoster.PrintAverageDaysInCourse(ID);                  // GetStudentID for argument to be
    }                                                              // passed to
                                                                   // PrintAverageDaysInCourse
    classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);
    
    classRoster.Remove("A3");
        
    classRoster.PrintAll();
        
    classRoster.Remove("A3");
    
    
    return 0;
}


