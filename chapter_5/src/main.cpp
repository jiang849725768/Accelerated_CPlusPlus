﻿#include <cstdio>

#include "question.h"

using namespace std;

int main()
{
	printf_s("输入题号(1~11):");
	switch (char label = getchar())
	{
	case '1':
		//练习5.1
		question_one();
	case '2':
		//练习5.2
		question_two();
	case '3':
		//练习5.3
		question_two();
	default:
		break;
	}
	

	//练习5.4
	//练习5.5
	//练习5.6
	//练习5.7
	//练习5.8
	//练习5.9
	//练习5.10
	//练习5.11

	return 0;
}