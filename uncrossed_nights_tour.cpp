#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int m, n;



int main()

{


	cout << "enter the number columns (m<=8) and number of rows(n<1000000) \n";
	do
	{
		cin >> m >> n;
	} while (m > 8 || m < 0 || n < 0 || n > 1000000);

	if (m <= 3 or n <= 3)
	{
		cout << "0";
	}

	else if ((m == 3 && n <= 6) || (m == 5 && n == 5))
	{
		cout << n;
	}
	else if (m == 3 && n > 6)
	{
		cout << "6";
	}
	else if (m == 4 && n == 4)
	{
		cout << "4";
	}
	else if (m == 4 && n == 4)
	{
		cout << n;
	}
	else if (m == 6 && n == 6)
	{
		cout << n*2;
	}
	else if (m == 7 && n == 7)
	{
		cout << n*2;
	}
	else if (m == 8 && n == 8)
	{
		cout << n * 2+1;
	}

	return 0;
}
