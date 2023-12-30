#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void changed(string w, int idx)
{
	if (idx == w.length())
	{
		return;
	}
	cout << w[idx];
	if (w[idx + 1] == w[idx])
	{
		cout << "*";
	}
	changed(w, idx + 1);

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
	changed(w, 0);
	return 0;
}
