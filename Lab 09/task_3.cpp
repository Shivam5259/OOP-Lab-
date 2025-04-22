#include "LectureCourse.h"
#include "LabCourse.h"
#include <iostream>
using namespace std;

int main() {
    Course* c1 = new LectureCourse("CS101", 3);
    Course* c2 = new LabCourse("CS102L", 2);

    Course* courses[] = {c1, c2};
    for (int i = 0; i < 2; ++i) {
        courses[i]->displayInfo();
        courses[i]->calculateGrade();
        cout << endl;
    }

    delete c1;
    delete c2;

    return 0;
}