//
//  main.cpp
//  StudentRosterClassProject
//
//  Created by Bryan Cimo on 2/3/21.
//

#include <iostream>
#include <sstream>
#include <string>
#include "roster.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {

    cout << "Scripting and Programming - Applications — C867, ";
    cout << "C++, ";
    cout << "001401087, ";
    cout << "Bryan Cimo" << endl << endl;
    
    Roster classRoster;
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Bryan,Cimo,bcimo@wgu.edu,48,7,10,4,SOFTWARE"};
    
    for (int i = 0; i < 5; ++i) {
        
        string studentString = studentData[i];
        vector<string> st;
        stringstream studentStream(studentString);
        while (studentStream.good()) {
            string substring;
            getline(studentStream, substring, ',');
            st.push_back(substring);
        }
        DegreeProgram degreeType = DegreeProgram::NETWORK;
        if (st.at(8).back() == 'Y') {
            degreeType = DegreeProgram::SECURITY;
        }
        if (st.at(8).back() == 'E') {
            degreeType = DegreeProgram::SOFTWARE;
        }
        classRoster.add(st.at(0), st.at(1), st.at(2), st.at(3), stoi(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeType);
    }
    
    classRoster.printAll();
    
    cout << "\n";
    
    classRoster.printInvalidEmails();
    
    cout << "\n";
    
    classRoster.printAverageDaysInCourse("A5");
    
    cout << "\n";
    
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    
    cout << "\n";
    
    classRoster.remove("A3");
    
    cout << "\n";
    
    classRoster.printAll();
    
    cout << "\n";
    
    classRoster.remove("A3");
    
    cout << "\n";
    
    return 0;
}
