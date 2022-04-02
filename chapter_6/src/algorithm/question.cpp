#include <cstdio>
#include <iostream>

#include "question.h"
#include "book.h"
#include "student_info.h"
#include "grade.h"
#include "framing.h"

using namespace std;

//chapter_6
void question_zero()
{
	vector<Student_info> did, didnt;

	for (int i = 0; i < 100; i++)
	{
		auto student = randomStudent();
		if (didAllHomework(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	if (did.empty())
	{
		printf_s("大家都是混子");
		return;
	}

	if (didnt.empty())
	{
		printf_s("大家都在卷");
		return;
	}

	writeAnalysis("median", medianAnalysis, did, didnt);
	writeAnalysis("average", averageAnalysis, did, didnt);
	writeAnalysis("optimistic", optimisticGradeAnalysis, did, didnt);
}

//6.1
void question_one()
{
	auto right_strings = genRanStr(7);
	auto left_strings = genRanStr(6);
	printfOut(frameIterator(right_strings));
	printfOut(frameIterator(left_strings));
	printfOut(heatIterator(left_strings, right_strings));
}

//6.2
void question_two()
{
	string a = "what http://something^wahy://fsss.com try";
	auto some_urls = findUrls(a);
	for (auto it = some_urls.begin(); it != some_urls.end(); it++)
	{
		printf_s((*it).c_str());
		putchar('\n');
	}
}

//6.3
void question_three()
{
	vector<int> u(10, 100);
	vector<int> v;
	copy(u.begin(), u.end(), v.begin());
	for (auto it = v.begin(); it != v.end(); it++)
		printf("%d\n", (*it));
}

//6.4
void question_four()
{
	//珍惜空间
	vector<int> u(10, 100);
	vector<int> v;
	copy(u.begin(), u.end(), back_inserter(v));
	for (auto it = v.begin(); it != v.end(); it++)
		printf("%d\n", (*it));
	//珍惜时间
	//vector<int> u(10, 100);
	//vector<int> v(u.size());
	//copy(u.begin(), u.end(), v.begin());
	//for (auto it = v.begin(); it != v.end(); it++)
	//	printf("%d\n", (*it));
}

//6.5
void question_five()
{
	vector<Student_info> did, didnt;

	for (int i = 0; i < 100; i++)
	{
		auto student = randomStudent();
		if (didAllHomework(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	if (did.empty())
	{
		printf_s("大家都是混子");
		return;
	}

	if (didnt.empty())
	{
		printf_s("大家都在卷");
		return;
	}

	writeAnalysis("optimistic", optimisticGradeAnalysis, did, didnt);
}

//6.6
void question_six()
{
	vector<Student_info> did, didnt;

	for (int i = 0; i < 100; i++)
	{
		auto student = randomStudent();
		if (didAllHomework(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	if (did.empty())
	{
		printf_s("大家都是混子");
		return;
	}

	if (didnt.empty())
	{
		printf_s("大家都在卷");
		return;
	}

	gradeAnalysis(did, gradeOptimisticMedian);
}

//6.7
void question_seven()
{
	vector<Student_info> students;

	for (int i = 0; i < 100; i++)
		students.push_back(randomStudent());

	vector<Student_info> did, didnt;
	didnt = extractDidnt(students);
	did = students;

	if (did.empty())
	{
		printf_s("大家都是混子");
		return;
	}

	if (didnt.empty())
	{
		printf_s("大家都在卷");
		return;
	}

	gradeAnalysis(did, gradeOptimisticMedian);
}

//6.8
void question_eight()
{
	//lazy
	printf_s("I am lazy, give up.\n");
}

//6.9
void question_nine()
{
	vector<string> some_strings = { "weqw"," 902","[\\]``","\n" };
	string new_string = conectStrings(some_strings);
	printf_s(new_string.c_str());
	putchar('\n');
}