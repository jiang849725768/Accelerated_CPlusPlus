#pragma once

#include <iostream>
#include <string>
#include <vector>

//计算成绩中位数
double medianGrade(std::vector<double> grades);

//计算成绩
double grade(double midterm, double final, std::vector<double> homework);

class Core
{
	friend class Student_info;
public:
	Core();

	Core(const Core&);
	virtual ~Core();


	explicit Core(std::istream& is);
	std::string name() const;


	bool valid() const;
	std::string letter_grade() const;

	virtual std::istream& read(std::istream&);
	virtual double grade() const;
	virtual bool great() const;

protected:
	virtual Core* clone() const;
	std::istream& read_common(std::istream&);
	std::istream& read_hw(std::istream& in);
	double midterm{}, final{};
	std::vector<double> homework;
	std::string n;
};

bool compare(const Core& c1, const Core& c2);

// ReSharper disable once CppInconsistentNaming
bool compare_grades(const Core& c1, const Core& c2);

// ReSharper disable once CppInconsistentNaming
bool compare_core_ptrs(const Core* cp1, const Core* cp2);
