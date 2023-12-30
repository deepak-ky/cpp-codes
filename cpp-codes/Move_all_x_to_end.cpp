#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
void movextoend(vector<char> &v, int idx, int len)
{
	if (idx == len)
	{
		return;
	}
	if (v[idx] == 'x')
	{
		v.erase(v.begin() + idx);
		v.push_back('x');
	}
	movextoend(v, idx + 1, len);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<char> v;
	char w[1000];
	cin >> w;
	int len = strlen(w);
	for (int i = 0; i < len; i++)
	{
		v.push_back(w[i]);
	}
	movextoend(v, 0, len);
	cout << "Updated vector is : ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	return 0;
}
