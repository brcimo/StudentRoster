//
//  student.cpp
//  StudentRosterClassProject
//
//  Created by Bryan Cimo on 2/3/21.
//

#include <iostream>
#include "student.h"

using std::cout;

Student::Student(string studentID, string firstName, string lastName, string email, int age, int completionDays[arraySizeDays], DegreeProgram degreeType) {
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->completionDays[0] = completionDays[0];
    this->completionDays[1] = completionDays[1];
    this->completionDays[2] = completionDays[2];
    this->degreeType = degreeType;
}

Student::~Student() {
    
}

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmail() {
    return email;
}

int Student::getAge() {
    return age;
}

int* Student::getcompletionDays() {
    return completionDays;
}

DegreeProgram Student::getDegreeType() {
    return degreeType;
}

void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setcompletionDays(int *completionDays) {
    this->completionDays[0] = completionDays[0];
    this->completionDays[1] = completionDays[1];
    this->completionDays[2] = completionDays[2];
}

void Student::setDegreeType(DegreeProgram degreeType) {
    this->degreeType = degreeType;
}

void Student::print() {
    cout << "ID: " << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Email: " << email << "\t";
    cout << "Age: " << age << "\t";
    cout << "Days in course: " << completionDays[0] << ", ";
    cout << " " << completionDays[1] << ", ";
    cout << " " << completionDays[2] << "\t";
    cout << "Degree Program: " << DegreeProgramString[(int)degreeType] << "\n";
}
