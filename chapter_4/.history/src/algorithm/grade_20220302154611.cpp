#include <stdexcept>
#include <algorithm>
#include "grade.h"

using namespace std;

double medianGrade(vector<double> grades)
{
    auto grades_size = grades.size();

    if (grades_size == 0)
    {
        throw domain_error ("Homework grades are empty");
    }

    sort(grades.begin(), grades.end());

    auto mid = grades_size / 2;

    return grades_size % 2 == 0 ? (grades[mid-1] + grades[mid]) / 2 : grades[mid];
}


double grade(double mid_grade, double fin_grade, const vector<double>& home_grades)
{
    double total_grade = mid_grade * 0.2 + fin_grade * 0.4 + medianGrade(home_grades) * 0.4;

    return total_grade;
}


double grade(const Student_info& student)
{
    double total_grade = student.midterm_grade * 0.2 + student.final_grade
                         * 0.4 + medianGrade(student.homework_grades);

    return total_grade;
}
