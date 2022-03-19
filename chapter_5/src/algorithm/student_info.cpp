#include <cstdio>
#include <random>
#include <iostream>
#include "student_info.h"
#include "grade.h"

using namespace std;

//����ѧ��������������
bool compareStudents(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

//����ѧ������
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

//�������һ����Ϊ��nobody����ѧ������ɼ�
Student_info randomStudent()
{
	//�������ӷ�����
	random_device rd;
	//�������������������
	default_random_engine rng{ rd() };
	//ָ����������ͺͷ�Χ
	uniform_int_distribution<int> random_grade{ 0,100 };
	uniform_int_distribution<int> random_grade_num{ 1,10 };

	//�������ѧ���ĳɼ�
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

//5.1.1�е�extract_fails����
vector<Student_info> extract_fails_origin(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	//ʼ��ʹstudents��[0, i]������ָԪ�سɼ�����
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

//ϰ��5.6��дextract_fails����
vector<Student_info> extract_fails_new(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;
	auto fail_num = students.size();

	//ʼ��ʹstudents��[0, i]������ָԪ�سɼ�����
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