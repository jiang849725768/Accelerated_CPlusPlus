#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm_grade, final_grade;
    std::vector<double> homework_grades;
};

bool compare(const Student_info& x, const Student_info& y);

bool read(Student_info& student);



#endif