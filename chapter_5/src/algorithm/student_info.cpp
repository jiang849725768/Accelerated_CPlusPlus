#include <cstdio>
#include <random>
#include <iostream>
#include "student_info.h"
#include "grade.h"

using namespace std;

//依据学生姓名进行排序
bool compareStudents(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}

//读入学生数据
bool readStudents(Student_info &student)
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

//提取挂科学生记录
students_type extractFailStudents(students_type& students)
{
	students_type fail_students{};

	students_type::iterator iter = students.begin();

	while(iter != students.end())
	{
		if (grade(*iter) < 60)
		{
			fail_students.push_back(*iter);
			iter = students.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	return fail_students;
}
