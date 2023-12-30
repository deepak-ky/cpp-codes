#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lb(int a[], int nn, int t)
{
	int idx = 0;
	for (int i = 0; i < nn; ++i)
	{
		/* code */
		if (a[i] > t)
		{

			idx = i;
			break;
		}

	}
	return idx;
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int money[] = {1, 2, 5, 10, 20, 50};
	int nn = sizeof(money) / sizeof(int);
	cout << nn << endl;
	int n;
	cin >> n;
	while (n > 0)
	{
		int ii = lb(money, nn, n);
		int idx = ii - 1;
		cout << money[idx] << ",";
		n = n - money[idx];
	}
	return 0;
}