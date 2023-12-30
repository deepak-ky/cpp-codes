#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
int printspan(stack<int> s, int x)
{
	s.pop();
	int count = 1;
	while ((s.top()) < x && (s.empty() == false))
	{
		count++;
		s.pop();
	}
	return count;
}
int* stackspan(int a[], int n)
{
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		s.push(a[i]);
	}
	int b[n];
	b[0] = 0;
	int j = 1;
	for (int i = 0; i < (n - 1); i++)
	{
		b[j++] = printspan(s, a[n - i - 1]);
		s.pop();
	}

	reverse(b + 1, b + n);
	return b;
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
	int* ans = stackspan(a, n);

	return 0;
}
