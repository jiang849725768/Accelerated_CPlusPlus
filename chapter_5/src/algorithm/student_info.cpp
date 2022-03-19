#include <cstdio>
#include <random>
#include <iostream>
#include "student_info.h"
#include "grade.h"

using namespace std;

//依据学生姓名进行排序
bool compareStudents(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

//读入学生数据
bool readStudents(Student_info& student)
{
	string name;
	name.resize(100);
	printf_s("Please enter student's name:");
	cin >> name;
	printf_s("Please enter student's midterm grade and final grade:");
	scanf_s(" %lf %lf", &student.midterm_grade, &student.final_grade);
	student.name = name;

	double homework_grade;
	printf_s("Please enter student's homework grades:");
	do
	{
		scanf_s("%lf", &homework_grade);
		student.homework_grades.push_back(homework_grade);
	} while (getchar() != '\n');

	return true;
}

//随机生成一个名为“nobody”的学生及其成绩
Student_info randomStudent()
{
	//定义种子发生器
	random_device rd;
	//定义随机数序列生成器
	default_random_engine rng{ rd() };
	//指定随机数类型和范围
	uniform_int_distribution<int> random_grade{ 0,100 };
	uniform_int_distribution<int> random_grade_num{ 1,10 };

	//随机生成学生的成绩
	Student_info student;
	student.name = "nobody";
	student.midterm_grade = random_grade(rng);
	student.final_grade = random_grade(rng);
	//printf_s("mid_grade: %.2lf, fin_grade: %.2lf",student.midterm_grade, student.final_grade);
	int homework_num = random_grade_num(rng);
	for (int i = 0; i < homework_num; i++)
	{
		student.homework_grades.push_back(random_grade(rng));
	}

	return student;
}

//5.1.1中的extract_fails函数
vector<Student_info> extract_fails_origin(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	//始终使students中[0, i]索引所指元素成绩及格
	while (i != students.size())
	{
		if (grade(students[i]) < 60)
		{
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
			++i;
	}

	return fail;
}

//习题5.6重写extract_fails函数
vector<Student_info> extract_fails_new(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;
	auto fail_num = students.size();

	//始终使students中[0, i]索引所指元素成绩及格
	while (i != students.size())
	{
		if (grade(students[i]) < 60)
		{
			fail.push_back(students[i]);
			if (fail_num == students.size())
				fail_num = i;
		}
		else
		{
			students[fail_num] = students[i];
			++fail_num;
		}
		++i;
	}
	students.resize(fail_num);

	return fail;
}