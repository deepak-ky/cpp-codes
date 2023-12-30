#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
void stockspan(int a[], int n)
{
	stack<int> s;
	int c[n] = {};
	s.push(0);
	for (int i = 0; i < n; i++)
	{
		while ((s.empty() == false) && a[s.top()] < a[i])
		{
			s.pop();
		}
		int ans = s.empty() ? 0 : s.top();
		int span = i - ans;
		c[i] = span;
		s.push(i);
	}

	for (int i = 0; i < n; ++i)
	{
		/* code */cout << c[i] << " ";
	}
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	stockspan(a, n);
	//int* ans = stackspan(a, n);
	//for (int i = 0; i < n; ++i)
	//{
	//	/* code */cout << ans[i] << " ";
	//}
	return 0;
}
