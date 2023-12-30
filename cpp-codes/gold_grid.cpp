#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	lli n;
	cin >> n;
	lli m;
	cin >> m;
	lli mat[n][n];
	for (lli i = 0; i < n; i++)
	{
		for (lli j = 0; j < n; j++)
		{
			mat[i][j] = 0;
		}

	}
	cout << "The original matrix : \n";
	for (lli i = 0; i < n; i++)
	{
		for (lli j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;

	}
	for (lli i = 0; i < m; i++)
	{
		lli x, y;
		cin >> x >> y;
		mat[x - 1][y - 1] = 1;
	}
	cout << "\nNow the matrix  is : \n";
	for (lli i = 0; i < n; i++)
	{
		for (lli j = 0; j < n; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;

	}
	lli ans = INT_MIN;

	for (lli i = 0; i <= (n - 2); i++)
	{
		for (lli j = 0; j <= (n - 2); j++)
		{
			cout << "\nThe horizontal line is in front of : " << j;
			cout << "\nThe vertical line is in front of : " << i;
			lli value, value1, value2;
			lli var1 = 0;
			lli var2 = 0;
			lli var3 = 0;
			lli var4 = 0;
			for (lli d = (i + 1); d <= (n - 1); d++)
			{
				for (lli e = 0; e <= j; e++)
				{
					var1 = var1 + mat[d][e];
				}
			}
			cout << endl << "Var 1 : " << var1;
			for (lli d = (i + 1); d <= (n - 1); d++)
			{
				for (lli e = (j + 1); e <= (n - 1); e++)
				{
					var2 = var2 + mat[d][e];
				}
			}
			cout << endl << "Var 2 : " << var2;
			for (lli d = 0; d <= (i); d++)
			{
				for (lli e = 0; e <= j; e++)
				{
					var3 = var3 + mat[d][e];
				}
			}
			cout << endl << "Var 3 : " << var3;
			for (lli d = 0; d <= i; d++)
			{
				for (lli e = (j + 1); e <= (n - 1); e++)
				{
					var4 = var4 + mat[d][e];
				}
			}
			cout << endl << "Var 4 : " << var4;
			value1 = min(var4, var3);
			value = min(var1, var2);
			value2 = min(value1, value);
			ans = max(ans, value2);
		}
	}
	cout << endl << "The ans is : " << ans;
	return 0;
}
