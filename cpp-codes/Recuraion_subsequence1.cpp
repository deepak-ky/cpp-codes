#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void subsequences(char a[], int idx, int val)
{
	if (idx == (val))
	{
		return;
	}
	int j = 0;
	int id = idx;
	while (id > 0)
	{
		int last_bit = (id & 1);
		if (last_bit)
		{
			cout << a[j];
		}
		j++;
		id  = id >> 1;
	}
	cout << ":";
	subsequences(a, idx + 1, val);
}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	char a[100];
	cin >> a;
	int len = strlen(a);
	cout << "Lenght is : " << len << endl;
	cout << "Test Check is " << a[len - 1] << endl;
	char b[100];
	int val = (1 << len);
	cout << "Total number of subsequence will be : " << val << endl;
	subsequences(a, 0, val);
	cout << endl << val;
	return 0;
}
