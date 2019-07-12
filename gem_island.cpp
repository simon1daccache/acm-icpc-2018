#include <iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void display(double total, int possibilities);
int factorial(int n);
void display1(int gems, int r);

int main()

{
	int n, d, r, gems;
	double total = 0;
	int possibilities = 0;

	cout << "enter the number of inhabitants, nights, and the maximum number of rich people \n";
	do
	{
		cin >> n >> d >> r;

	} while (n < 1 || d>500 || r<1 || r>n);


	gems = n + d;

	if (n == 1 && d != 0)
	{
		total = gems;
		possibilities = n;
		display(total, possibilities);
		return 0;
	}
	else if (d == 0)
	{
		total = r;
		possibilities = 1;
		display(total, possibilities);
		return 0;
	}

	else
	{


		if (gems % 2 != 0)
		{
			possibilities = n * n ;

			for (int i = 0; i < n; i++)

				total += (float)(gems - 1 - i) * n;

		}
		else
		{
			possibilities = n * n + 1;
			total = (float)((gems - 1) * (n * n) + (r * r));
		}

	}


	display(total, possibilities);
	
	return 0;

}
void display(double total, int possibilities)
{
	printf("%.7lf\n", (float)((total) / possibilities));
}

// factorial function if needed 
int factorial(int n) 
{
	if (n == 0)
	{
		return(1);
	}
	else if (n == 1)
	{
		return(1);
	}
	else
		return(n * factorial(n - 1));
}

/*
	n!/(r!(n-r)!)

	n is the total number of items in this case is the total number of gems

	r is the total number of items that i need to choose

*/
// display the probability function
void display1(int gems, int r)
{

	printf("%.7lf\n", (float)(factorial(gems) / (factorial(r)*(factorial(gems)-factorial(r)) )));
}
