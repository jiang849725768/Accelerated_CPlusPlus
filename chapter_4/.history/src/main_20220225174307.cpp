#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	cout << "Enter midterm and final exam grades:" << endl;
	printf("Something");
	double midterm, finalterm;
	cin >> midterm >> finalterm;


	cout << "Enter all homework grades,"
			"followed by end-of-files:" << endl;
	
	int count = 0;
	double sum = 0;

	double x;

	while (cin >> x){
		++count;
		sum += x;
	}

	streamsize prec = cout.precision();
	cout << "Final grade is " << setprecision(3)
	<< 0.2 * midterm + 0.4 * finalterm + 0.4 * sum/count
	<< setprecision(prec) << endl;

	//getchar();
	
	return 0;
}
