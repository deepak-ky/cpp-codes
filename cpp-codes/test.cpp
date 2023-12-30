#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	vector<pair<int, int>> v;
	v.push_back({1, 2});
	for (auto x : v)
	{
		cout << x.first << " " << x.second << endl;
	}
	cout << "hello , now I really don't care";
	return 0;
}