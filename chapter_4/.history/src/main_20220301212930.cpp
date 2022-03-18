#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "student_info.h"
#include "grade.h"

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	printf_s("Please enter students' names and grades:");

	while(readStudents(record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compareStudents);
	
	for(vector<Student_info>::size_type i = 0;
	i != students.size(); ++i)
	{
		try
		{
			double total_grade = grade(students[i]);
			printf("%s \t %lf", students[i].name.c_str(), total_grade);
		}
		catch(domain_error e)
		{
			printf(e.what());
		}
		
	}

	return 0;
}
