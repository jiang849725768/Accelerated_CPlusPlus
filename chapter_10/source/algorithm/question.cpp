#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

#include "question.h"
#include "book.h"
#include "answer.h"
#include "Student_info.h"
#include "String_list.h"

using namespace std;

//chapter_X
void questionZero()
{
	//10.1.1
	int x = 5;
	//p指向x
	int* p = &x;
	cout << "x=" << x << endl;
	//通过p改变x的值
	*p = 6;
	cout << "x=" << x << endl;

	//10.3
	cout << letter_grade(77) << endl;
	//10.5.2
	ifstream infile("./data/in");
	ofstream outfile("./data/out");

	string s;
	while (getline(infile, s))
		outfile << s << endl;
}

//10-1
void questionOne()
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
			cout << setprecision(3) << letter_grade(final_grade) << setprecision(pres) << endl;
		}
		catch (const domain_error& e)
		{
			cout << e.what() << endl;
		}
	}
}

//10-2
void questionTwo()
{
	double a[3] = {0, 2, 1};
	cout << median<double*, double>(a, a + 3) << endl;
}

//10-3
void questionThree()
{
	double a[3] = {0, 2, 1};
	double b[4] = {1, 3, 2, 4};
	vector<double> c = {0, 1, 2};
	vector<double> d = {1, 3, 2, 4};
	cout << median<double*, double>(a, a + 3) << endl;
	cout << median<double*, double>(b, b + 4) << endl;
	cout << median<vector<double>::iterator, double>(c.begin(), c.end()) << endl;
	cout << median<vector<double>::iterator, double>(d.begin(), d.end()) << endl;
}

//10-4
void questionFour()
{
	string strings_list[] = {"one", "two", "three", "four", "five"};
	String_list a(strings_list, std::size(strings_list));
	a.self_print();
}

//10-5
void questionFive()
{
	string strings_list[] = {"one", "two", "three", "four", "five"};
	const String_list a(strings_list, std::size(strings_list));
	for (auto& it : a)
		cout << it << endl;
	auto it = a.end();
	do
	{
		it--;
		cout << *it << endl;
	}
	while (it != a.begin());
}

//10-6
void questionSix()
{
	const string s = "a test of split";
	String_list word_list;
	auto result = split(s);
	result.self_print();
}
