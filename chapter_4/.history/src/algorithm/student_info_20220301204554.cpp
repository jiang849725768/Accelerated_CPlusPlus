#include "student_info.h"

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

bool read(Student_info& student)
{
    scanf_s("%s %lf %lf", &student.name, &student.midterm_grade, &student.final_grade);
    double homework_grade;
    while(scanf_s("%ld", &homework_grade))
    {
        student.homework_grades.push_back(homework_grade);
    }
}