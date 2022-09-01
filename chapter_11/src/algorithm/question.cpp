#include "question.h"

#include <cstdio>
#include <iostream>
#include <vector>

#include "book.h"
#include "grade.h"
#include "Student_info.h"
#include "Student_info_new.h"
#include "framing.h"

using namespace std;

//chapter_11
void questionZero()
{
}

//11-1
void questionOne()
{
	//没有分配空间，只需使用各数据成员自身的复制构造，赋值和析构函数
}

//11-2
void questionTwo()
{
	//各数据成员皆为C++标准数据库成员，有自己的默认构造函数，类自我生成的默认构造函数会调用这些函数进行默认构造
}

//11-3
void questionThree()
{
	//对各数据成员依次调用各自的赋值操作
}

//11-4
void questionFour()
{
	//2个，C++内置类型为POD类，不需要也没有析构函数
}

//11-5
void questionFive()
{
	vector<Student_info> did, didnt;
	cout << &did << endl;
	cout << &didnt << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "------------------" << endl;
		Student_info student;
		student.random_generate();
		if (student.did_all_homework())
			did.push_back(student);
		else
			didnt.push_back(student);
		cout << "Student " << i + 1 << " create." << endl;
	}
	if (did.empty())
	{
		cout << "No student did all the homework!" << endl;
		return;
	}

	if (didnt.empty())
	{
		cout << "Every student did all the homework!" << endl;
		return;
	}

	writeAnalysis("median", medianAnalysis, did, didnt);
	writeAnalysis("average", averageAnalysis, did, didnt);
	writeAnalysis("optimistic", optimisticGradeAnalysis, did, didnt);
}

//11-6
void questionSix()
{
	Vec<double> ret(8, 1);
	const auto it = ret.begin();
	for (int i = 0; it + i != ret.end(); ++i)
		*(it + i) += i;

	ret.erase(it + 3);
	for (const auto& item : ret)
		cout << item << " ";
	cout << endl;

	ret.clear();
	cout << "Size after clear: " << ret.size() << endl;
}

//11-7
void questionSeven()
{
	//const Student_info_new student(cin);
	//cout << student.grade() << endl;
	const Vec<string> random_strings = genRanStr(7);

	const auto frame_strings = center(random_strings);
	printfOut(frame_strings);
}

//11-8
void questionEight()
{
}

//11-9
void questionNine()
{
}

//11-10
void questionTen()
{
}

//11-11
void questionEleven()
{
}
