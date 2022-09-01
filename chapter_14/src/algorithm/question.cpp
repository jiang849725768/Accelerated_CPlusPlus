#include "question.h"

#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>

#include "Core.h"
#include "Grad.h"
#include "Handle.h"
#include "Student_info.h"
#include "Ptr.h"
#include "Str.h"
#include "Ptr_new.h"

using namespace std;

//chapter_14
void questionZero()
{
	vector<Handle<Core>> students;
	Handle<Core> record;
	char ch;
	string::size_type maxlen = 0;

	while (cin >> ch)
	{
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;
		record->read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare_Core_handles);

	for (const auto& student : students)
	{
		cout << student->name() << string(maxlen + 1 - student->name().size(), ' ');
		try
		{
			const double final_grade = student->grade();
			const streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error& e)
		{
			cout << e.what() << endl;
		}
	}
}

//14-1
void questionOne()
{
	const Ptr<Core> student_a = new Core(cin);
	const Ptr<Core> student_b = new Core(cin);
	cout << student_a->name() << " " << student_b->name() << endl;
	const auto result = compare_Core_Ptrs(student_a, student_b) ? "True" : "False";
	cout << "Compare result: " << result << endl;
}

//14-2
void questionTwo()
{
	vector<Ptr<Core>> students;
	Ptr<Core> record;
	char ch;
	string::size_type maxlen = 0;

	while (cin >> ch)
	{
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;
		record->read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare_Core_Ptrs);

	for (const auto& student : students)
	{
		cout << student->name() << string(maxlen + 1 - student->name().size(), ' ');
		try
		{
			const double final_grade = student->grade();
			const streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error& e)
		{
			cout << e.what() << endl;
		}
	}
}

//14-3
void questionThree()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//read and store data
	while (record.read(cin))
	{
		maxlen = max(maxlen, record.name().size());
		cout << "before push back" << endl;
		students.push_back(record);
		cout << "after push back" << endl;
	}

	sort(students.begin(), students.end(), Student_info::compare);

	for (const auto& student : students)
	{
		//student is a ptr to uncall the function
		cout << student.name() << string(maxlen + 1 - student.name().size(), ' ');
		try
		{
			const double final_grade = student.grade();
			const streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error& e)
		{
			cout << e.what() << endl;
		}
	}
}

//14-4
void questionFour()
{
	const Str a = "There is ";
	const Str b = "a sentence.";
	cout << a + b << endl;
}

//14-5
void questionFive()
{
	const Str a = "There is ";
	cout << a.ec_str() << '\0' << endl;
}

//14-6
void questionSix()
{
	vector<Ptr_new<Core>> students;
	Ptr_new<Core> record;
	char ch;
	string::size_type maxlen = 0;

	while (cin >> ch)
	{
		if (ch == 'U')
			record = new Core;
		else
			record = new Grad;
		record->read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compareCorePtrs);

	for (const auto& student : students)
	{
		cout << student->name() << string(maxlen + 1 - student->name().size(), ' ');
		try
		{
			const double final_grade = student->grade();
			const streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error& e)
		{
			cout << e.what() << endl;
		}
	}
}

//14-7
void questionSeven()
{
}

//14-8
void questionEight()
{
}

//14-9
void questionNine()
{
}

//14-10
void questionTen()
{
}

//14-11
void questionEleven()
{
}
