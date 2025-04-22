#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"

class LectureCourse : public Course{
public:
    LectureCourse(string code, int cr);
    void calculateGrade();
    void displayInfo();
};

#endif
