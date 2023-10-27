//
//  roster.h
//  StudentRosterClassProject
//
//  Created by Bryan Cimo on 2/3/21.
//

#ifndef roster_h
#define roster_h

#include <stdio.h>
#include <vector>
#include "student.h"
#include "degree.h"

using std::vector;

class Roster {
public:
    const static int numStudents = 5;
    Student *classRosterArray[numStudents];
private:
    int addStudentPosition = -1;
    vector<string> parsedStudent;
    
public:
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};

#endif /* roster_h */
