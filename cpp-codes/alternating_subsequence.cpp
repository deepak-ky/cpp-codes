#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		if (a[0] > 0)
		{
			int currmax = a[0];
			int sum = 0;
			int flag = 2;
			for (int i = 1; i < n; i++)
			{
				cout << "\nIteration : " << i;
				cout << "\nA[i] here : " << a[i];
				cout << "\nFlag here : " << flag;
				cout << "\nCuurmax here : " << currmax;
				cout << " \nsum here : " << sum;
				if (flag == 2)
				{
					if (a[i] > 0 && a[i + 1] < 0)
					{
						if (a[i] > currmax)
						{
							sum = sum + a[i];
							currmax = a[i + 1];
							flag = 1;
						}
						else
						{
							sum = sum + currmax;
							flag = 2;
						}
					}
					else if (a[i] > 0 && a[i + 1] > 0)
					{
						if (a[i] > currmax)
						{
							currmax = a[i];
						}
					}
				}
				else if (flag == 1)
				{
					if (a[i] < 0 && a[i + 1] > 0)
					{
						if (a[i] >= currmax)
						{
							sum = sum + a[i];
							currmax = a[i + 1];
							flag = 2;
						}
						else
						{
							sum = sum + currmax;
							flag = 2;
						}
					}
					else if (a[i] < 0 && a[i + 1] < 0)
					{
						if (a[i] >= currmax)
						{
							currmax = a[i];
						}
					}

				}
			}
			cout << "\nThe currmax here : " << currmax;
			cout << "\nThe sum here : " << sum;
			cout << "\nThe answer is : " << sum + currmax;
		}
	}
	return 0;
}
