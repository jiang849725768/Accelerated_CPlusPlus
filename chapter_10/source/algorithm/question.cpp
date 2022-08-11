#include <cstdio>
#include <iostream>
#include <fstream>

#include "question.h"
#include "book.h"

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
}

//10-2
void questionTwo()
{
}

//10-3
void questionThree()
{
}

//10-4
void questionFour()
{
}

//10-5
void questionFive()
{
}

//10-6
void questionSix()
{
}
