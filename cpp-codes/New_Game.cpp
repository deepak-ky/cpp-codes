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
	string s;
	getline(cin, s);
	// int tillhere = 0;
	// for (int i = 0; s[i] != '\0'; i++)
	// {
	// 	if (s[i] == ' ')
	// 	{
	// 		reverse(s.begin() + tillhere, s.begin() + i);
	// 		tillhere = i + 1;
	// 	}
	// 	if (s[i + 1] == '\0')
	// 	{
	// 		reverse(s.begin() + tillhere, s.begin() + (i + 1));
	// 	}


	// }


	cout << s;
	return 0;
}
