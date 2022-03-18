# include <iostream>

using namespace std;

int main()
{
	int x = 1;
	int y = x++;
	{
		cout << "x:" << x << "y:" << y << endl;
	}
	
	getchar();
	return 0;
}
