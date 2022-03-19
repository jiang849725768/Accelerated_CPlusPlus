#ifndef GUARD_student_info_h
#define GUARD_student_info_h
#include <string>
#include <vector>
#include <list>

struct Student_info {
    std::string name;
    double midterm_grade = 0;
    double final_grade = 0;
    std::vector<double> homework_grades;
};

//依据学生姓名进行排序
bool compareStudents(const Student_info& , const Student_info&);

//读入学生数据
bool readStudents(Student_info&);

//随机生成一个名为“nobody”的学生及其成绩
Student_info randomStudent();

//5.1.1中的extract_fails函数
std::vector<Student_info> extract_fails_origin(std::vector<Student_info>&);

//习题5.6重写extract_fails函数
std::vector<Student_info> extract_fails_new(std::vector<Student_info>&);

#endif