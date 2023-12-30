#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void remove(string w, int idx)
{
	if (idx == w.length())
	{
		return;
	}
	if (w[idx] != w[idx - 1])
		cout << w[idx];
	if (w[idx + 1] == w[idx])
	{
		return remove(w, idx + 2);
	}
	else
		return remove(w, idx + 1);

}
int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string w;
	cin >> w;
	remove(w, 0);
	return 0;
}
