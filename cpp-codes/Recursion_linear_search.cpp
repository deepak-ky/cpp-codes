#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findindex(int a[], int n, int idx, int m)
{
	if (idx == n)
	{
		return -1;
	}
	if (a[idx] == m)
	{
		return idx;
	}
	return findindex(a, n, idx + 1, m);
}
int firstoccurence(int *a, int n, int m)
{
	if ( n == 0)
	{
		return -1;
	}
	if (a[0] == m)
	{
		return 0;
	}
	int i = firstoccurence(a + 1, n - 1, m);
	if ( i == -1) return -1;
	else return i + 1; // 0 + 1 => 1 + 1 => 2 + 1 that is how correct index in returned
}
int main()
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
	int m;
	cin >> m;
	cout << findindex(a, n, 0, m);
	cout << endl << firstoccurence(a, n, m);

	return 0;
}
