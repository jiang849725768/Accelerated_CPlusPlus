#include "Student_info_new.h"

#include <numeric>
#include <stdexcept>


double grade(const double midterm, const double final, Vec<double> homework)
{
	if (homework.empty())
		throw std::domain_error("Student has done no homework");
	//懒得再抄中值，用平均值代替
	const double homework_sum = std::accumulate(homework.begin(), homework.end(), 0.0);
	const double homework_grade = homework_sum / static_cast<double>(homework.size()); //均值
	return 0.2 * midterm + 0.4 * final + 0.4 * homework_grade;
}

Student_info_new::Student_info_new(): midterm(0), final(0)
{
}


Student_info_new::Student_info_new(std::istream& is)
{
	read(is);
}

double Student_info_new::grade() const
{
	return ::grade(midterm, final, homework);
}

double Student_info_new::grade2() const
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework_grade;
}

std::istream& Student_info_new::read(std::istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in);
	return in;
}

std::istream& Student_info_new::read_hw(std::istream& in)
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

bool compare(const Student_info_new& x, const Student_info_new& y)
{
	return x.name() < y.name();
}
