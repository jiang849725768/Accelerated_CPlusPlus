#include <cstdio>
#include <random>
#include <iostream>
#include "student_info.h"
#include "grade.h"

using namespace std;

//����ѧ��������������
bool compareStudents(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}

//����ѧ������
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

//��ȡ�ҿ�ѧ����¼
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
