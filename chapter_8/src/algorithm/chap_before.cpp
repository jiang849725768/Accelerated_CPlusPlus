// ReSharper disable CppUseRangeAlgorithm
#include "chap_before.h"

#include <algorithm>
#include <numeric>

using std::domain_error;
using std::vector;
using std::cout;
using std::endl;

//4.1
//根据学生的期中考试、期末考试成绩以及家庭作业成绩来计算总成绩
double grade(const double midterm, const double final, const double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//4.1.1
//计算一个 vector＜double＞类型的变量的中值
//需要注意的是，调用函数时整个vector 参数都会被复制
double median(vector<double> vec)
{
	using vec_sz = vector<double>::size_type;
	const vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());
	const vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

//4.1.2
//根据期中、期末考试成绩以及保存家庭作业的向量来计算学生的总成绩
//这个函数不用复制它的参数，因为median已经为完成了这个工作
double grade(const double midterm, const double final, const vector<double>& hw)
{
	if (hw.empty())
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

//4.2.2
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

//6.2.1
//检查学生是否完成全部家庭作业
bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) ==
		s.homework.end());
}

//6.2.2
double grade_aux(const Student_info& s)
{
	try
	{
		return grade(s);
	}
	catch (domain_error& e)
	{
		cout << e.what() << endl;
		return grade(s.midterm, s.final, 0);
	}
}

//6.2.2
double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(),
	          back_inserter(grades), grade_aux);
	return median(grades);
}

//计算成绩平均数(6.2.3)
double average(const std::vector<double>& grades)
{
	//使用0.0以保证结果为double
	return accumulate(grades.begin(), grades.end(), 0.0) / static_cast<double>(grades.size());
}

//计算以平均数计算家庭作业成绩后的总成绩(6.2.3)
double average_grade(const Student_info& a_student)
{
	return grade(a_student.midterm, a_student.final, average(a_student.homework));
}

//6.2.3
double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(),
	          back_inserter(grades), average_grade);
	return median(grades);
}

//6.2.4
//s.homework的非零元素的中值；如果不存在这样的元素，则为0
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(),
	            back_inserter(nonzero), 0);
	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	return grade(s.midterm, s.final, median(nonzero));
}
