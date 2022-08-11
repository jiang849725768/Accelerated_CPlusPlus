#ifndef GUARD_CHAP_BEFORE_H
#define GUARD_CHAP_BEFORE_H

#include <vector>
#include <iostream>

struct Student_info
{
	std::string name;
	double midterm = 0;
	double final = 0;
	std::vector<double> homework;
};

//4.1
//根据学生的期中考试、期末考试成绩以及家庭作业成绩来计算总成绩
double grade(double midterm, double final, double homework);

//4.1.1
//计算一个 vector＜double＞类型的变量的中值
//需要注意的是，调用函数时整个vector 参数都会被复制
double median(std::vector<double> vec);

//4.1.2
//根据期中、期末考试成绩以及保存家庭作业的向量来计算学生的总成绩
//这个函数不用复制它的参数，因为median已经为完成了这个工作
double grade(double midterm, double final, const std::vector<double>& hw);

//4.2.2
double grade(const Student_info&);

//6.2.1
//检查学生是否完成全部家庭作业
bool did_all_hw(const Student_info&);

//6.2.2
double grade_aux(const Student_info&);

//6.2.2
double median_analysis(const std::vector<Student_info>&);

//计算成绩平均数(6.2.3)
double average(const std::vector<double>&);

//计算以平均数计算家庭作业成绩后的总成绩(6.2.3)
double average_grade(const Student_info&);

//6.2.3
double average_analysis(const std::vector<Student_info>&);

//6.2.4
//s.homework的非零元素的中值；如果不存在这样的元素，则为0
double optimistic_median(const Student_info&);


#endif
