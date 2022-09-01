#include "question.h"

#include <codecvt>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


#include "list_file_name.h"

#include "FileHelper.h"

using namespace std;


//chapter_X
void questionZero()
{
	vector<string> src_files_names;
	getFileNames(R"(./src)", src_files_names);

	for (const auto& file_name : src_files_names)
	{
		cout << string(10, '-') << file_name << string(10, '-') << endl;
		auto result = FileHelper::ReadTextFile(file_name);
		for (auto& sentence : result)
			cout << sentence << endl;
		ifstream ifs;
		ifs.open(file_name);
		char ch;
		for (int i = 0; i < 3; ++i)
			ifs >> ch;
		while (!ifs.eof())
		{
			string line;
			getline(ifs, line);
			//cout << line << endl;
			auto wline = utf8ToUnicode(line.c_str());
			wcout.imbue(locale("chs"));
			wcout << wline << endl;
			delete[] wline;
		}
		ifs.close();
	}
}

//X-1
void questionOne()
{
}

//X-2
void questionTwo()
{
}

//X-3
void questionThree()
{
}

//X-4
void questionFour()
{
}

//X-5
void questionFive()
{
}

//X-6
void questionSix()
{
}

//X-7
void questionSeven()
{
}

//X-8
void questionEight()
{
}

//X-9
void questionNine()
{
}

//X-10
void questionTen()
{
}

//X-11
void questionEleven()
{
}
