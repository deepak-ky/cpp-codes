#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	lli t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 9; i++)

		{
			string s;
			cin >> s;
			for (int i = 0; i < 9; i++)
			{
				if (s[i] == '1')
				{
					s[i] = '2';
				}
			}
			cout << s << endl;
		}
	}
	return 0;
}
