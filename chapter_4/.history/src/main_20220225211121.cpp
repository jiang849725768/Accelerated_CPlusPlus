#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cout << "Enter midterm and final exam grades:" << endl;
	double midterm, finalterm;
	cin >> midterm >> finalterm;

	vector<double> homework;
	while(true){
		cout << "Enter all homework grades,"
			"followed by end-of-files:" ;

		double x;

		while (cin >> x){
			homework.push_back(x);
		}
		
		auto homework_size = homework.size();

		if (homework_size){
			break;
		}
		else{
			cout << "Enter something" ;
			continue;
		}
	}

	sort(homework.begin(), homework.end());
	auto homework_size = homework.size();
	auto mid = homework_size / 2;
	double mid_grade;
	mid_grade = homework_size % 2 == 0 ? (homework[mid-1] + homework[mid]):
										homework[mid];
	

	streamsize prec = cout.precision();
	cout << "Final grade is " << setprecision(3)
	<< 0.2 * midterm + 0.4 * finalterm + 0.4 * mid_grade
	<< setprecision(prec) << endl;

	//getchar();
	
	return 0;
}
