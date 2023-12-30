#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
int checkin(int freq[], int s, int e)
{


	int pp = 0;
	for (int i = s; i <= e; i++)
	{
		if (freq[i] == 1)
		{
			pp++;
		}
	}
	return pp;
}

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
		int k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int freq[200005] = {0};
		for (int i = 1; i <= (n - 2); i++)
		{
			if (a[i] > a[i - 1] && a[i] > a[i + 1])
			{

				freq[i] = 1;
			}
		}
		int maxpeak = 0;
		int p;
		int bestindex = 0;
		for (int i = 0; i <= n - 1 ; i++)
		{
			int peak;
			peak = checkin(freq, i + 1, ( i + k) - 2);
			if (peak > maxpeak)
			{
				maxpeak = peak;
				bestindex = i + 1;
			}
			else if (peak <= maxpeak)
			{
				maxpeak = maxpeak;

			}

		}
		if (maxpeak == 0 && bestindex == 0 )
		{
			bestindex++;
		}
		cout << (maxpeak + 1) << " " << bestindex << endl;
	}
	return 0;
}
