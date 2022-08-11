#include "question.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

#include "book.h"
#include "Student_info.h"
#include "Student_info_new.h"

using namespace std;

//chapter_X
void questionZero()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlength = 0;

	//读并存储数据
	while (record.read(cin))
	{
		maxlength = max(maxlength, record.name().size());
		students.push_back(record);
	}
	cin.clear();
	//按字母顺序排列学生记录
	sort(students.begin(), students.end(), compare);

	//写姓名和成绩
	for (auto& student : students)
	{
		cout << student.name() << string(maxlength + 1 - student.name().size(), ' ');
		try
		{
			const double final_grade = student.grade();
			const streamsize pres = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(pres) << endl;
		}
		catch (const domain_error& e)
		{
			cout << e.what() << endl;
		}
	}
}


//9-1
void questionOne()
{
	const Student_info student_a(cin);
	cout << student_a.grade2() << endl;
}

//9-2
void questionTwo()
{
	//需删除函数compare的Student_info&参数的const限定符，因为常量对象无法访问类中的非常量函数
}

//9-3
void questionThree()
{
	const Student_info student_a;
	//捕获异常
	try
	{
		cout << student_a.grade() << endl;
	}
	catch (const domain_error& e)
	{
		cout << e.what() << endl;
		cout << "捕获成功" << endl;
	}
	//仅触发异常
	cout << student_a.grade() << endl;
}

//9-4
void questionFour()
{
	Student_info student_a;
	if (student_a.valid())
		cout << student_a.grade() << endl;
	else
	{
		cout << "Student's data is empty, please enter student's data first" << endl;
		student_a.read(cin);
		cout << student_a.name() << "\'s final grade is " << student_a.grade2() << endl;
	}
}

//9-5
void questionFive()
{
	vector<Student_info_new> students;
	Student_info_new record;
	string::size_type maxlen = 0;

	//读并存储数据
	while (record.read(cin))
	{
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	cin.clear();
	//按字母顺序排列学生记录
	sort(students.begin(), students.end(), compareNew);

	//写姓名和成绩
	for (auto& student : students)
	{
		cout << student.name() << string(maxlen + 1 - student.name().size(), ' ');
		cout << student.grade() << endl;
	}
}

//9-6
void questionSix()
{
	vector<Student_info_new> students;
	Student_info_new record;
	string::size_type maxlen = 0;

	//读并存储数据
	while (record.read(cin))
	{
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	cin.clear();
	//按字母顺序排列学生记录
	sort(students.begin(), students.end(), compareNew);
	//按通过未通过二次排序
	stable_partition(students.begin(), students.end(), isPass);


	//写姓名和成绩
	for (auto& student : students)
	{
		cout << student.name() << string(maxlen + 1 - student.name().size(), ' ');
		cout << student.grade() << endl;
	}
}

//9-7
void questionSeven()
{
	//私有成员函数
}
