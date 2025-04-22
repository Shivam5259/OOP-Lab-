#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"

class LabCourse : public Course{
public:
    LabCourse(string code, int cr);
    void calculateGrade();
    void displayInfo();
};

#endif