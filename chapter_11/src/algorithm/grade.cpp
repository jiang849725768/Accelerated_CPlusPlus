#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "grade.h"

using namespace std;

//计算成绩平均数(6.2.3)
double averageGrade(std::vector<double> grades)
{
	//使用0.0以保证结果为double
	return accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
}

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


//获取学生总成绩向量中位数（家庭作业以中位数计算）（6.2.2）
double medianAnalysis(const std::vector<Student_info>& students)
{
	vector<double> grades;
	grades.reserve(students.size());
	for (Student_info student : students)
	{
		grades.push_back(student.grade_aux());
	}

	return (medianGrade(grades));
}

//获取学生总成绩向量中位数（家庭作业以平均数计算）（6.2.3）
double averageAnalysis(const std::vector<Student_info>& students)
{
	vector<double> grades;
	grades.reserve(students.size());
	for (Student_info student : students)
	{
		grades.push_back(student.grade_average());
	}

	return (medianGrade(grades));
}

//获取学生总成绩向量中位数（家庭作业以乐观中位数计算）（6-5）
double optimisticGradeAnalysis(const std::vector<Student_info>& students)
{
	vector<double> grades;
	grades.reserve(students.size());
	for (Student_info student : students)
	{
		grades.push_back(student.grade_optimistic_median());
	}

	return medianGrade(grades);
}


//输出学生集合间的成绩差异(每个集合的成绩中值)（6.2.2）
void writeAnalysis(const std::string& name, double analysis(const std::vector<Student_info>&),
                   const std::vector<Student_info>& didStudents, const std::vector<Student_info>& didntStudents)
{
	printf_s("%s :median(完成所有作业的学生) = %.2lf \n", name.c_str(), analysis(didStudents));
	printf_s("median(未完成的学生) = %.2lf \n", analysis(didntStudents));
}
