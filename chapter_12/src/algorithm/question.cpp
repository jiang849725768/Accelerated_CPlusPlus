#include "question.h"

#include <cstdio>
#include <iostream>

#include "book.h"
#include "framing.h"
#include "Str.h"
#include "Str_new.h"

using namespace std;

//chapter_12
void questionZero()
{
}

//12-1
void questionOne()
{
	Str_new a(5, 'a');
}

//12-2
void questionTwo()
{
	Str_new a(5, 'a');
	cout << a.c_str() << endl;
	cout << strlen(a.data()) << endl;
	cout << a.data() << 'e' << '\0' << endl;
	const auto x = new char[3];
	a.copy(x, 3);
	cout << x[0] << x[1] << x[2] << endl;

	delete[] x;
}

//12-3
void questionThree()
{
	Str_new a(5, 'a');
	Str_new b(6, 'b');
	Str_new c(4, 'c');
	cout << "a-b: " << strcmp(a, b) << endl;
	cout << "a-c: " << strcmp(a, c) << endl;
}

//12-4
void questionFour()
{
	Str_new a1(5, 'a');
	Str_new a2(5, 'a');
	Str_new b(5, 'b');
	Str_new a3(4, 'a');
	if (a1 == a2)
		cout << "a1==a2" << endl;
	if (a1 == b)
		cout << "a1==b" << endl;
	if (a1 == a3)
		cout << "a1==a3" << endl;
	if (a1 != a2)
		cout << "a1!=a2" << endl;
	if (a1 != b)
		cout << "a1!=b" << endl;
	if (a1 != a3)
		cout << "a1!=a3" << endl;
}

//12-5
void questionFive()
{
	Str_new a(5, 'a');
	auto b = "bbbbbb";
	cout << (a + b).c_str() << endl;
}

//12-6
void questionSix()
{
	Str_new a;
	if (a)
		cout << "a1 isn't empty" << endl;
	else
		cout << "a1 is empty" << endl;
	a = Str_new(5, 'a');
	if (a)
		cout << "a2 isn't empty" << endl;
	else
		cout << "a2 is empty" << endl;
}

//12-7
void questionSeven()
{
	Str_new a1(5, 'a');
	for (auto it = a1.begin(); it != a1.end(); ++it) // NOLINT(modernize-loop-convert)
	{
		cout << *it << endl;
	}
}

//12-8
void questionEight()
{
	Str_new a1;
	getline(cin, a1);
	cout << a1 << endl;
}

//12-9
void questionNine()
{
	const Str_new a1(4, 'a');
	cout << a1 << endl;
}

//12-10
void questionTen()
{
}

//12-11
void questionEleven()
{
	auto strings = genRanStr(7);
	printfOut(strings);
	return;
	auto frame_strings = center(strings);
	printfOut(frame_strings);
}

//12-12
void questionTwelve()
{
}

//12-13
void questionThirteen()
{
}

//12-14
void questionFourteen()
{
}

//12-15
void questionFifteen()
{
}
