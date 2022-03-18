#include <stdio.h>
#include "student_info.h"

using namespace std;

bool compareStudents(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}

bool readStudents(Student_info &student)
{
    string name;
    name.resize(100);
    printf_s("Please enter student's name:");
    scanf("%s", &name[0]);
    printf_s("Please enter student's midterm grade and final grade:");
    scanf_s(" %lf %lf", &student.midterm_grade, &student.final_grade);
    student.name = name;

    double homework_grade;
    printf_s("Please enter student's homework grades:");
    do
    {
        scanf_s("%lf", &homework_grade);
        student.homework_grades.push_back(homework_grade);
    } while (getchar() != '\n');

    return true;
}