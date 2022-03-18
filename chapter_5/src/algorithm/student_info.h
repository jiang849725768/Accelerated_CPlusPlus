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

//将学生列表类型定义为list/vector
typedef std::vector<Student_info> students_type;

//依据学生姓名进行排序
bool compareStudents(const Student_info& , const Student_info&);

//读入学生数据
bool readStudents(Student_info&);

//随机生成一个名为“nobody”的学生及其成绩
Student_info randomStudent();

//提取挂科学生记录
students_type extractFailStudents(students_type&);

#endif