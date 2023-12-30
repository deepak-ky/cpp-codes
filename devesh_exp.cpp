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
	int n = 3, a[3], x, c, max[3], min[3], e[3][4];
	cout << "For variables" << endl;
	cout << "Enter the minimum, and maximum Limits of the variables";
	for (int y = 0; y < n; y++)
	{
		cin >> min[y];
		cin >> max[y];
	}
	for (x = 0; x < n; x++)
	{
		a[x] = (min[x] + max[x]) / 2;
	}

	for (int a1 = 0; a1 < n; a1++)
	{

		e[a1][0] = min[a1];
		e[a1][1] = min[a1] + 1;
		e[a1][3] = max[a1] - 1;
		e[a1][4] = max[a1];
	}
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < 4; j++)
		{
			for (int l = 1; l <= i + 1; l++)
			{
				if (l != 1)
				{
					cout << a[2] << "\t";
				}
			}
			cout << e[i][j] << "\t";
			for (int k = 0; k < n - (i + 1); k++)
			{
				cout << a[k] << "\t";
			}
			cout << "\n";
		}
	}

	return 0;
}