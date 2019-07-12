/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int r, c;
	do {
		cout << "Please enter the number of lines (between 1 and 3000) and the number of columns (between 1 and 6000): ";
		cin >> r >> c;
	} while (r < 1 || r > 3000 || c < 1 || c > 6000);
	cin.ignore();
	r = 2 * r - 1;
	c = 2 * c - 1;
	string* table;
	cout << "Please enter the table: " << endl;
	table = new string[r];
	for (int i = 0; i < r; i++) {
		getline(cin, table[i]);
	}
	cout << "The table is: " << endl;
	for (int i = 0; i < r; i++) {
		cout << table[i];
		cout << endl;
	}
	int trCount = 0;
	for (int i = 0; i < r; i = i + 2) {
		for (int j = 0; j < c; j++) {
			if (table[i][j] == 'x') { // i/j is the first star
				for (int j2 = j + 1; j2 < c; j2++) {
					if (table[i][j2] == ' ')
						break;
					if (table[i][j2] == 'x') { // i/j2 is the second star
						int y = (j + j2) / 2;
						int x = i - (j2 - j) / 2;
						if (x >= 0) { // still inside the table
							if (table[x][y] == 'x') { // x/y is the third star
								int ti, tj;
								for (ti = i - 1, tj = j + 1; ti > x; ti--, tj++)
									if (table[ti][tj] != '/' && table[ti][tj] != 'x' && table[ti][tj] != '-')
										break;
								if (ti == x) { // second line exists
									for (ti = i - 1, tj = j2 - 1; ti > x; ti--, tj--)
										if (table[ti][tj] != '\\' && table[ti][tj] != 'x' && table[ti][tj] != '-')
											break;
									if (ti == x) // third line exists
										trCount++;
								}
							}
						}
						x = i + (j2 - j) / 2;
						if (x < r) { // still inside the table
							if (table[x][y] == 'x') { // x/y is the third star
								int ti, tj;
								for (ti = i + 1, tj = j + 1; ti < x; ti++, tj++)
									if (table[ti][tj] != '\\' && table[ti][tj] != 'x' && table[ti][tj] != '-')
										break;
								if (ti == x) { // second line exists
									for (int ti = i + 1, tj = j2 - 1; ti < x; ti++, tj--)
										if (table[ti][tj] != '/' && table[ti][tj] != 'x' && table[ti][tj] != '-')
											break;
									if (ti == x) // third line exists
										trCount++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << trCount;
	return 0;
}
