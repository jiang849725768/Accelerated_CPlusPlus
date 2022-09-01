#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

double averageGrade(std::vector<double>);

//计算成绩中位数
double medianGrade(std::vector<double>);

double grade(const Student_info&);

//获取学生总成绩向量中位数（家庭作业以中位数计算）（6.2.2）
double medianAnalysis(const std::vector<Student_info>&);

//指定grade版本的辅助函数(6.2.2)
double gradeAux(const Student_info&);

//获取学生总成绩向量中位数（家庭作业以平均数计算）（6.2.3）
double averageAnalysis(const std::vector<Student_info>&);

//获取学生总成绩向量中位数（家庭作业以乐观中位数计算）（6-5）
double optimisticGradeAnalysis(const std::vector<Student_info>&);

//输出学生集合间的成绩差异（6.2.2）
void writeAnalysis(const std::string&, double analysis(const std::vector<Student_info>&),
                   const std::vector<Student_info>&, const std::vector<Student_info>&);
#endif
