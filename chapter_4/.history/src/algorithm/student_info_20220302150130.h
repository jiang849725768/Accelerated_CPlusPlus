#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm_grade, final_grade;
    std::vector<double> homework_grades;
};

bool compareStudents(const Student_info& , const Student_info&);

bool readStudents(Student_info&);

#endif