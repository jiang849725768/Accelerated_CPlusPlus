#include "student_info.h"

bool compareStudents(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

bool readStudents(Student_info& student)
{
    char* name;
    scanf_s("%s %lf %lf", &name, &student.midterm_grade, &student.final_grade);
    student.name = name;

    double homework_grade;
    while(scanf_s("%ld", &homework_grade))
    {
        student.homework_grades.push_back(homework_grade);
    }
}