#include "Core.h"

#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;

//计算成绩中位数
double medianGrade(vector<double> grades)
{
	const auto grades_size = grades.size();

	if (grades_size == 0)
	{
		throw domain_error("Homework grades are empty");
	}

	sort(grades.begin(), grades.end());

	const auto mid = grades_size / 2;

	return grades_size % 2 == 0 ? (grades[mid - 1] + grades[mid]) / 2 : grades[mid];
}

double grade(const double midterm, const double final, const std::vector<double> homework)
{
	if (homework.empty())
		throw std::domain_error("Student has done no homework");
	const double homework_grade = medianGrade(homework);
	return 0.2 * midterm + 0.4 * final + 0.4 * homework_grade;
}

Core::Core(): midterm(0), final(0)
{
	std::cerr << "Core constructor once" << std::endl;
}

Core::Core(const Core& c) = default;

Core::~Core()
{
	std::cerr << "Core destructor once" << std::endl;
}

Core::Core(std::istream& is)
{
	std::cerr << "Core read constructor once" << std::endl;
	Core::read(is);
}

std::string Core::name() const
{
	//std::cout << "Core::name" << std::endl;
	return n;
}

std::istream& Core::read(std::istream& in)
{
	read_common(in);
	read_hw(in);
	return in;
}

double Core::grade() const
{
	//std::cout << "Core::grade" << std::endl;
	return ::grade(midterm, final, homework);
}

bool Core::great() const
{
	return valid();
}

bool Core::valid() const
{
	return !homework.empty();
}

std::string Core::letter_grade() const
{
	//分数成绩的界限
	const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};
	//字母成绩表示
	const char* letters[] = {
		"A+", "A", "(A-)", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};
	//根据数组大小及单个元素大小计算成绩个数
	constexpr size_t ngrades = std::size(numbers);
	//根据分数成绩得到相应字母成绩
	for (size_t i = 0; i < ngrades; i++)
	{
		if (grade() >= numbers[i])
			return letters[i];
	}
	return "?\?\?";
}

Core* Core::clone() const
{
	return new Core(*this);
}

std::istream& Core::read_common(std::istream& in)
{
	//read student name & test grade then store it
	in >> n >> midterm >> final;
	return in;
}

std::istream& Core::read_hw(std::istream& in)
{
	if (in)
	{
		homework.clear();
		double x;
		char ch;
		in.get(ch);
		if (ch == '\n')
			return in;
		in.unget();
		while (in >> x)
		{
			homework.push_back(x);
			in.get(ch);
			if (ch == '\n')
				return in;
			in.unget();
		}

		in.clear(); //用于将cin失败复位,会吞掉^Z
	}
	return in;
}

bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2)
{
	return c1.grade() < c2.grade();
}

bool compare_core_ptrs(const Core* cp1, const Core* cp2)
{
	return compare(*cp1, *cp2);
}
