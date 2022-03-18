#include "student_info.h"

using namespace std;

bool compareStudents(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

bool readStudents(Student_info& student)
{
    string name;
    name.resize(100);
    scanf_s("%s %lf %lf", &name[0], &student.midterm_grade, &student.final_grade);
    student.name = name;

    double homework_grade;
    while(scanf_s("%lf", &homework_grade))
    {
        student.homework_grades.push_back(homework_grade);
    }

    return true;
}