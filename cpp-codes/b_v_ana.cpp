#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n = 3;
	cout << "For 3 variables : ";
	cout << "Enter the maximum and minimum values for 3 variables : ";
	int maxi[3], mini[3];
	for (int i = 0; i < n; i++)
	{
		cin >> mini[i];
		cin >> maxi[i];
	}
	int mid[3];
	for (int i = 0; i < n; i++)
	{
		mid[i] = (mini[i] + maxi[i]) / 2;
	}
	int c, table[3][4];
	for (int i = 0; i < n; i++)
	{
		table[i][0] = mini[i];
		table[i][1] = mini[i] + 1;
		table[i][3] = maxi[i] - 1;
		table[i][4] = maxi[i];
	}
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < 4; j++)
		{
			for (int l = 1; l <= i + 1; l++)
			{
				if (l != 1)
				{
					cout << mid[2] << "\t";
				}
			}
			cout << table[i][j] << "\t";
			for (int k = 0; k < n - (i + 1); k++)
			{
				cout << mid[k] << "\t";
			}
			cout << "\n";
		}
	}
	return 0;
}