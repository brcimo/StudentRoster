//
//  student.h
//  StudentRosterClassProject
//
//  Created by Bryan Cimo on 2/3/21.
//

#ifndef student_h
#define student_h

#include <string>
#include "degree.h"

using std::string;

class Student {
    
public:
    const static int arraySizeDays = 3;
    
private:
    string studentID = "";
    string firstName = "";
    string lastName = "";
    string email = "";
    int age = -1;
    int completionDays[arraySizeDays] = {0, 0, 0};
    DegreeProgram degreeType = DegreeProgram::SECURITY;
    
public:
    Student(string studentID, string firstName, string lastName, string email, int age, int completionDays[arraySizeDays], DegreeProgram degreeType);
    ~Student();
    
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getcompletionDays();
    DegreeProgram getDegreeType();
    
    void setStudentID(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmail(string);
    void setAge(int);
    void setcompletionDays(int[arraySizeDays]);
    void setDegreeType(DegreeProgram);
    
    void print();
};

#endif /* student_h */
