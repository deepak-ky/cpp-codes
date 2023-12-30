#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
void printindices(lli a[], lli n, lli m, lli idx)
{
	if (idx == n)
	{
		return;
	}
	if (a[idx] == m)
	{
		cout << idx << " ";
	}
	return printindices(a, n, m, idx + 1);
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	lli n;
	cin >> n;
	lli a[n];
	for (lli i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	lli m;
	cin >> m;
	printindices(a, n, m, 0);
	return 0;
}
