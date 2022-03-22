#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "student_info.h"

double medianGrade(std::vector<double>);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif