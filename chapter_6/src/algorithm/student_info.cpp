#include <cstdio>
#include <random>
#include <iostream>
#include <algorithm>

#include "student_info.h"
#include "grade.h"

using namespace std;

//����ѧ��������������
bool compareStudents(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

//�ҵ�ͨ�����Ե�ѧ��
bool pgrade(const Student_info& a_student)
{
	if (grade(a_student) >= 60)
		return true;
	return false;
}

//�ҵ�δͨ�����Ե�ѧ��
bool fgrade(const Student_info& a_student)
{
	return !pgrade(a_student);
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
	uniform_int_distribution<int> random_homework_grade{ -10,100 };
	uniform_int_distribution<int> random_grade_num{ 1,10 };

	//�������ѧ���ĳɼ�
	Student_info student;
	student.name = "nobody";
	student.midterm_grade = random_grade(rng);
	student.final_grade = random_grade(rng);
	//printf_s("mid_grade: %.2lf, fin_grade: %.2lf",student.midterm_grade, student.final_grade);
	//int homework_num = random_grade_num(rng);
	int homework_num = 7;
	for (int i = 0; i < homework_num; i++)
	{
		int homework_grade = random_homework_grade(rng);
		if (homework_grade < 0)
			homework_grade = 0;
		student.homework_grades.push_back(homework_grade);
	}

	return student;
}

//��ȡ�ҿ�ѧ��(6.3.1)��2�ɼ�����ÿѧ��ÿ�Σ�
vector<Student_info> extractFails(vector<Student_info>& students)
{
	vector<Student_info> fail;

	remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);

	students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

	return fail;
}

//��ȡ�ҿ�ѧ��(6.3.2)��1�ɼ�����ÿѧ��ÿ�Σ�
std::vector<Student_info> greaterExtractFails(std::vector<Student_info>& students)
{
	auto iter = stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());

	return fail;
}

//�ж�ѧ���Ƿ��������еļ�ͥ��ҵ(6.2.1)
bool didAllHomework(const Student_info& a_student)
{
	return ((find(a_student.homework_grades.begin(),
		a_student.homework_grades.end(), 0)) == a_student.homework_grades.end());
}

//��ȡδ���ȫ����ͥ��ҵѧ��(6-7)��1�ɼ�����ÿѧ��ÿ�Σ�
std::vector<Student_info> extractDidnt(std::vector<Student_info>& students)
{
	auto iter = stable_partition(students.begin(), students.end(), didAllHomework);
	vector<Student_info> didnt(iter, students.end());
	students.erase(iter, students.end());

	return didnt;
}