#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std;



int main()

{
	int m, n;
	cout << "enter the number columns (m<8) and number of rows(n<1000000) \n";
	do 
	{
		cin >> m >> n;
	} while (m > 8 || m < 0 || n < 0 || n>1000000);
	


	return 0;
}
