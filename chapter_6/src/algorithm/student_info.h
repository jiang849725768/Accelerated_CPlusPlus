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
bool compareStudents(const Student_info&, const Student_info&);

//找到通过考试的学生
bool pgrade(const Student_info&);

//找到未通过考试的学生
bool fgrade(const Student_info&);

//读入学生数据
bool readStudents(Student_info&);

//随机生成一个名为“nobody”的学生及其成绩
Student_info randomStudent();

//提取挂科学生(6.3.1)（2成绩计算每学生每次）
std::vector<Student_info> extractFails(std::vector<Student_info>&);

//提取挂科学生(6.3.2)（1成绩计算每学生每次）
std::vector<Student_info> greaterExtractFails(std::vector<Student_info>&);

//判断学生是否做了所有的家庭作业(6.2.1)
bool didAllHomework(const Student_info&);

//提取未完成全部家庭作业学生(6-7)（1成绩计算每学生每次）
std::vector<Student_info> extractDidnt(std::vector<Student_info>&);

#endif