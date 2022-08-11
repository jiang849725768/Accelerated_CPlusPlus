#include "book.h"

#include <algorithm>

double grade(const double midterm, const double final, std::vector<double>& homework)
{
	const auto grades_size = homework.size();

	if (grades_size == 0)
	{
		throw std::domain_error("Homework grades are empty");
	}

	std::sort(homework.begin(), homework.end());

	const auto mid = grades_size / 2;
	const double homework_grade = grades_size % 2 == 0 ? (homework[mid - 1] + homework[mid]) / 2 : homework[mid];
	const double total_grade = midterm * 0.2 + final * 0.4 + homework_grade * 0.4;

	return total_grade;
}
