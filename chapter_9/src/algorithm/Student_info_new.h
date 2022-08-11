#pragma once
#include <iostream>
#include <string>

class Student_info_new
{
public:
	Student_info_new();
	explicit Student_info_new(std::istream& in);
	double grade_value() const;
	char grade() const;
	std::string name() const;
	std::istream& read(std::istream& in);
private:
	double final = 0;
	double midterm = 0;
	std::string student_name;
};

//比较排列学生名字
bool compareNew(const Student_info_new& x, const Student_info_new& y);

//判定及格
bool isPass(const Student_info_new& x);
