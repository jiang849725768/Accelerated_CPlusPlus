#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	vector<double> aset = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto aset_size = aset.size();

	sort(aset.rbegin(),aset.rend());

	vector<vector<double>> sets(4);
	for(int i = 0; i < 4; i++)
	{
		auto start = aset_size * i /4;
		auto end = aset_size * (i+1) / 4;
		for(auto j = start; j < end; j++)
		{
			sets[i].push_back(aset[j]);
		}
	}

	for (auto it = sets.begin(); it != sets.end(); it++)
	{
		vector<double> sset = *it;
		for(auto iit = sset.begin(); iit != sset.end(); iit++)
		{
			cout << *iit << " ";
		}
		cout << "\n" << endl;
	}

	
	return 0;
}
