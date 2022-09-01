#include "question.h"

#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <vector>

#include "book.h"
#include "Grad.h"
#include "Student_info.h"


using namespace std;

//chapter_13
void questionZero()
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

//13-1
void questionOne()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	//read and store data
	while (record.read(cin))
	{
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
}

//13-2
void questionTwo()
{
	// ReSharper disable once CppUseAuto
	Core* p1 = new Core;
	// use Core()

	Core* p2 = new Grad;
	// use Core(),Grad()

	Core s1;
	// use Core()

	Grad s2;
	// use Core(),Grad()

	try
	{
		p1->grade();
		// use Core::grade()
	}
	catch (domain_error& e)
	{
		cout << e.what() << endl;
	}

	p1->name();
	// use Core::name()

	try
	{
		p2->grade();
		// use Grad::grade(),Core::grade()
	}
	catch (domain_error& e)
	{
		cout << e.what() << endl;
	}

	p2->name();
	// use Core::name()

	try
	{
		s1.grade();
		// use Core::grade()
	}
	catch (domain_error& e)
	{
		cout << e.what() << endl;
	}

	s1.name();
	// use Core::name()

	try
	{
		s2.grade();
		// use Grad::grade(),Core::grade()
	}
	catch (domain_error& e)
	{
		cout << e.what() << endl;
	}

	s2.name();
	// use Core::name()
}

//13-3
void questionThree()
{
	const Student_info graduate(cin);

	if (graduate.valid())
		cout << graduate.name() << " did all homework." << endl;
	else
		cout << graduate.name() << " forget homework at all" << endl;
}

//13-4
void questionFour()
{
	const Student_info graduate(cin);

	cout << graduate.name() << " grade: " << graduate.grade()
		<< ", letter_grade: " << graduate.letter_grade() << endl;
}

//13-5
void questionFive()
{
	const Student_info graduate(cin);

	if (graduate.great())
		cout << "The student is a great one." << endl;
	else if (graduate.valid())
		cout << "The student doesn't finish thesis" << endl;
	else
		cout << "The student doesn't finish homework" << endl;
}

//13-6
void questionSix()
{
	const auto hc_student = Student_info(cin);
	const streamsize prec = cout.precision();
	if (hc_student.pass())
		cout << setprecision(3) << "Pass with " << hc_student.grade() << setprecision(prec) << endl;
	else
		cout << setprecision(3) << "Fail with " << hc_student.grade() << setprecision(prec) << endl;
}

//13-7
void questionSeven()
{
	const Student_info audit_student(cin);

	if (audit_student.grade() == NULL)
		cout << "This is an audit student" << endl;
}

//13-8
void questionEight()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	//read and store data
	while (record.read(cin))
	{
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), Student_info::compare);

	for (const auto& student : students)
	{
		//student is a ptr to uncall the function
		cout << student.name() << string(maxlen + 1 - student.name().size(), ' ');
		try
		{
			const double final_grade = student.grade();
			if (final_grade == NULL)
				cout << "None" << endl;
			else
			{
				const streamsize prec = cout.precision();
				cout << setprecision(3) << final_grade << setprecision(prec) << endl;
			}
		}
		catch (domain_error& e)
		{
			cout << e.what() << endl;
		}
	}
}

//13-9
void questionNine()
{
	//delete cp and then try to clone an nonexisted cp
}

//13-10
void questionTen()
{
}

//13-11
void questionEleven()
{
}
