#include "Student_info_new.h"

Student_info_new::Student_info_new(): final(0), midterm(0)
{
}

Student_info_new::Student_info_new(std::istream& in)
{
	read(in);
}

double Student_info_new::grade_value() const
{
	return 0.5 * midterm + 0.5 * final;
}

char Student_info_new::grade() const
{
	return grade_value() >= 60 ? 'P' : 'F';
}

std::string Student_info_new::name() const
{
	return student_name;
}

std::istream& Student_info_new::read(std::istream& in)
{
	if (in)
		in >> student_name >> midterm >> final;
	return in;
}

bool compareNew(const Student_info_new& x, const Student_info_new& y)
{
	return x.name() < y.name();
}

bool isPass(const Student_info_new& x)
{
	return x.grade() == 'P';
}
