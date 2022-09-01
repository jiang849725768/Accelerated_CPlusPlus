#pragma once
#include <iostream>
#include "Vec.h"

//计算总成绩
double grade(double midterm, double final, Vec<double> homework);

class Student_info_new
{
public:
	Student_info_new();
	//显式声明防止隐式转换
	explicit Student_info_new(std::istream& is);

	double grade() const;
	//9-1
	double grade2() const;
	std::istream& read(std::istream&);
	std::string name() const { return n; }
	bool valid() const { return !homework.empty(); }

private:
	std::string n;
	double midterm = 0;
	double final = 0;
	Vec<double> homework;
	//9-1
	double homework_grade = 0;
	//9-7
	std::istream& read_hw(std::istream& in);
};

//比较排列学生名字
bool compare(const Student_info_new& x, const Student_info_new& y);
