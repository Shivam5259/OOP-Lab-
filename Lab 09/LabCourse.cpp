#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string code, int cr): Course(code, cr) {}

void LabCourse::calculateGrade(){
    cout<<"Calculating Lab Course Grade"<<endl;
}

void LabCourse::displayInfo(){
    cout<<"Lab Course\nCode: "<<courseCode<<"\tCredits: "<<credits<<endl;
}
