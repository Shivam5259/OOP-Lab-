#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int cr): Course(code, cr){}

void LectureCourse::calculateGrade(){
    cout<<"Calculating Lecture Course Grade"<<endl;
}

void LectureCourse::displayInfo(){
    cout<<"Lecture Course\nCode: "<<courseCode<<"\tCredits: "<<credits<<endl;
}
