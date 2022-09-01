#pragma once
#include <iostream>
#include <vector>


//计算总成绩
double grade(double midterm, double final, std::vector<double> homework);

class Student_info
{
public:
	Student_info();
	//显式声明防止隐式转换
	explicit Student_info(std::istream& is);
	Student_info(const Student_info&);
	~Student_info();

	Student_info& operator=(const Student_info&);

	Student_info& random_generate();

	//判断学生是否做了所有的家庭作业(6.2.1)
	bool did_all_homework();

	double grade() const;
	//计算学生总成绩，指定计算方式
	double grade(double calculateGrade(std::vector<double>));
	std::istream& read(std::istream&);
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }

	//指定grade版本的辅助函数(6.2.2)
	double grade_aux();

	//计算以平均数计算家庭作业成绩后的总成绩
	double grade_average();

	//计算学生乐观中值估计成绩（忽略0分）（6.2.4）
	double grade_optimistic_median();

private:
	std::string n;
	double midterm = 0;
	double final = 0;
	std::vector<double> homework;
	//9-1
	double homework_grade = 0;
	//9-7
	std::istream& read_hw(std::istream& in);
};

//比较排列学生名字
bool compare(const Student_info& x, const Student_info& y);
