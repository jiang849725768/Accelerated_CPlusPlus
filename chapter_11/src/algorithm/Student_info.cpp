#include "Student_info.h"

#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iostream>
#include <random>
#include <vector>
#include "grade.h"

using std::cout;
using std::endl;
using std::vector;
using std::domain_error;

double grade(const double midterm, const double final, const std::vector<double> homework)
{
	if (homework.empty())
		throw std::domain_error("Student has done no homework");
	const double homework_grade = medianGrade(homework);
	return 0.2 * midterm + 0.4 * final + 0.4 * homework_grade;
}

Student_info::Student_info(): midterm(0), final(0), homework_grade(0)
{
	cout << "Create " << this << endl;
}


Student_info::Student_info(std::istream& is)
{
	read(is);
	cout << "Create " << this << endl;
}

Student_info::Student_info(const Student_info& old_student)
{
	n = old_student.n;
	midterm = old_student.midterm;
	final = old_student.final;
	homework = old_student.homework;
	homework_grade = old_student.homework_grade;
	cout << "Duplicate " << &old_student << " to " << this << endl;
}

Student_info::~Student_info()
{
	cout << "Delete " << this << endl;
}

Student_info& Student_info::operator=(const Student_info& right_student)
{
	n = right_student.n;
	midterm = right_student.midterm;
	final = right_student.final;
	homework = right_student.homework;
	homework_grade = right_student.homework_grade;
	cout << "Assign once" << endl;

	return *this;
}

Student_info& Student_info::random_generate()
{
	//定义种子发生器
	std::random_device rd;
	//定义随机数序列生成器
	std::default_random_engine rng{rd()};
	//指定随机数类型和范围
	std::uniform_int_distribution<int> random_grade{0, 100};
	std::uniform_int_distribution<int> random_homework_grade{-10, 100};
	std::uniform_int_distribution<int> random_grade_num{1, 10};

	n = "nobody";
	midterm = random_grade(rng);
	final = random_grade(rng);
	//printf_s("mid_grade: %.2lf, fin_grade: %.2lf",student.midterm_grade, student.final_grade);
	//int homework_num = random_grade_num(rng);
	constexpr int homework_num = 7;
	for (int i = 0; i < homework_num; i++)
	{
		int rand_grade = random_homework_grade(rng);
		if (rand_grade < 0)
			rand_grade = 0;
		homework.push_back(rand_grade);
	}
	for (double& grade : homework)
	{
		grade *= 3;
		if (grade >= 100)
			grade = 100;
	}

	return *this;
}

bool Student_info::did_all_homework()
{
	return ((std::find(homework.begin(), homework.end(), 0)) == homework.end());
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

double Student_info::grade(double calculateGrade(std::vector<double>))
{
	const double total_grade = midterm * 0.2 + final * 0.4 + calculateGrade(homework) * 0.4;

	return total_grade;
}

std::istream& Student_info::read(std::istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in);
	return in;
}

double Student_info::grade_average()
{
	return grade(averageGrade);
}

double Student_info::grade_optimistic_median()
{
	vector<double> nonzero;
	remove_copy(homework.begin(), homework.end(), back_inserter(nonzero), 0);

	//避免全为0分的情况
	if (nonzero.empty())
		return grade(medianGrade);
	const vector<double> save = homework;
	homework = nonzero;
	const auto student_grade = grade(medianGrade);
	homework = save;
	return student_grade;
}

std::istream& Student_info::read_hw(std::istream& in)
{
	if (in)
	{
		double homework_sum = 0;
		homework.clear();
		double x;
		while (in >> x)
		{
			homework_sum += x;
			homework.push_back(x);
		}
		homework_grade = homework_sum / static_cast<double>(homework.size());
		in.clear(); //用于将cin失败复位,会吞掉^Z
	}
	return in;
}

double Student_info::grade_aux()
{
	try
	{
		return grade();
	}
	catch (domain_error&)
	{
		return grade(medianGrade);
	}
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}
