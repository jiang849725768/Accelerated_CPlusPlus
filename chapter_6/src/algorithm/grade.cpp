#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "grade.h"

using namespace std;

//计算成绩平均数(6.2.3)
double averageGrade(const std::vector<double> grades)
{
	//使用0.0以保证结果为double
	return accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
}

//计算成绩中位数
double medianGrade(vector<double> grades)
{
	auto grades_size = grades.size();

	if (grades_size == 0)
	{
		throw domain_error("Homework grades are empty");
	}

	sort(grades.begin(), grades.end());

	auto mid = grades_size / 2;

	return grades_size % 2 == 0 ? (grades[mid - 1] + grades[mid]) / 2 : grades[mid];
}

//计算学生总成绩，指定计算方式
double grade(const double mid_grade, const double fin_grade, const std::vector<double>& home_grades, double calculateGrade(const std::vector<double>))
{
	double total_grade = mid_grade * 0.2 + fin_grade * 0.4 + calculateGrade(home_grades) * 0.4;

	return total_grade;
}

double grade(const Student_info& student)
{
	double total_grade = student.midterm_grade * 0.2 + student.final_grade
		* 0.4 + medianGrade(student.homework_grades) * 0.4;

	return total_grade;
}

//指定grade版本的辅助函数(6.2.2)
double gradeAux(const Student_info& a_student)
{
	try {
		return grade(a_student);
	}
	catch (domain_error) {
		return grade(a_student.midterm_grade, a_student.final_grade, a_student.homework_grades, medianGrade);
	}
}
//计算以平均数计算家庭作业成绩后的总成绩
double gradeAverage(const Student_info& a_student)
{
	return grade(a_student.midterm_grade, a_student.final_grade, a_student.homework_grades, averageGrade);
}

//计算学生乐观中值估计成绩（忽略0分）（6.2.4）
double gradeOptimisticMedian(const Student_info& a_student)
{
	vector<double> nonzero;
	remove_copy(a_student.homework_grades.begin(), a_student.homework_grades.end(), back_inserter(nonzero), 0);

	//避免全为0分的情况
	if (nonzero.empty())
		return grade(a_student.midterm_grade, a_student.final_grade, a_student.homework_grades, medianGrade);
	else
		return grade(a_student.midterm_grade, a_student.final_grade, nonzero, medianGrade);
}

//获取学生总成绩向量中位数（家庭作业以中位数计算）（6.2.2）
double medianAnalysis(const std::vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), gradeAux);

	return(medianGrade(grades));
}

//获取学生总成绩向量中位数（家庭作业以平均数计算）（6.2.3）
double averageAnalysis(const std::vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), gradeAverage);

	return(medianGrade(grades));
}

//获取学生总成绩向量中位数（家庭作业以乐观中位数计算）（6-5）
double optimisticGradeAnalysis(const std::vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), gradeOptimisticMedian);

	return medianGrade(grades);
}

//获取学生总成绩向量中位数（家庭作业以指定方式计算）（6-6）
double gradeAnalysis(const std::vector<Student_info>& students, double specialAnalysis(const Student_info&))
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), specialAnalysis);

	return medianGrade(grades);
}

//输出学生集合间的成绩差异(每个集合的成绩中值)（6.2.2）
void writeAnalysis(const std::string& name, double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>& didStudents, const std::vector<Student_info>& didntStudents)
{
	printf_s("%s :median(完成所有作业的学生) = %.2lf \n", name.c_str(), analysis(didStudents));
	printf_s("median(未完成的学生) = %.2lf \n", analysis(didntStudents));
}