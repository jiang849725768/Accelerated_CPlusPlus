#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	cout << "Enter midterm and final exam grades:";
	double midterm, finalterm;
	cin >> midterm >> finalterm;

	cout << "Enter all homework grades,"
			"followed by end-of-files:";
	
	int count = 0;
	double sum = 0;

	double x;

	while (cin >> x){
		++count;
		sum += x;
	}

	streamsize prec = cout.precision();
	cout << "Final grade is " << setprecision(5)
	<< 0.2 * midterm + 0.4 * finalterm + 0.4 * sum/count
	<< setprecision(prec) << endl;

	return 0;
}
