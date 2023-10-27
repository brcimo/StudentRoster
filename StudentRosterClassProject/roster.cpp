//
//  roster.cpp
//  StudentRosterClassProject
//
//  Created by Bryan Cimo on 2/3/21.
//

#include <iostream>
#include "roster.h"

using std::cout;
    
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    
    int daysArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++addStudentPosition] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
}

void Roster::remove(string studentID) {
    
    bool found = false;
    for (int i = 0; i <= addStudentPosition; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            Student *temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[addStudentPosition];
            classRosterArray[addStudentPosition] = temp;
            cout << studentID << " has been removed from the roster.\n";
            addStudentPosition--;
        }
    }
    if (!found) {
        cout << "Did not find student with ID: " << studentID << "\n";
    }
}

void Roster::printAll() {
    
    cout << "All Students in the Roster:\n";
        
    for (int i = 0; i <= addStudentPosition; ++i) {
        classRosterArray[i]->print();
    }
}
    
void Roster::printAverageDaysInCourse(string studentID) {
    
    cout << "Average Days in Course for ";
    for (int i = 0; i <= addStudentPosition; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            cout << classRosterArray[i]->getFirstName() << " ";
            cout << classRosterArray[i]->getLastName() << ", " << studentID << ":\t";
            cout << (((double)classRosterArray[i]->getcompletionDays()[0]
                     + (double)classRosterArray[i]->getcompletionDays()[1]
                     + (double)classRosterArray[i]->getcompletionDays()[2]) / 3.0)
            << "\n";
        }
    }
}
    
void Roster::printInvalidEmails() {

    bool didFindInvalidEmail = false;
    for (int i = 0; i <= addStudentPosition; ++i) {
        string currentEmail = classRosterArray[i]->getEmail();
        bool containsAt = false;
        bool containsDot = false;
        bool containsSpace = false;
        for (int j = 0; j < currentEmail.length(); ++j) {
            if (currentEmail[j] == '@') {
                containsAt = true;
            }
            if (currentEmail[j] == '.') {
                containsDot = true;
            }
            if (currentEmail[j] == ' ') {
                containsSpace = true;
                break;
            }
        }
        if (containsAt == false || containsDot == false || containsSpace == true) {
            cout << "Student: " << classRosterArray[i]->getStudentID() << " has an invalid email: " << classRosterArray[i]->getEmail() << "\n";
            didFindInvalidEmail = true;
        }
    }
    if (didFindInvalidEmail == false) {
        cout << "Did not find invalid email.\n";
    }
}
    
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    cout << "Students in " << DegreeProgramString[(int)degreeProgram] << " program:\n";
    for (int i = 0; i <= addStudentPosition; ++i) {
        if (classRosterArray[i]->getDegreeType() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster()
{
    for (int i = 0; i < numStudents; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
