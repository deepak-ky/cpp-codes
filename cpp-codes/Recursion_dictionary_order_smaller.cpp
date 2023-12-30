#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printtillend(string s, string w)
{
	if (s == w)
	{
		return;
	}
	cout << s << endl;
	bool val = next_permutation(s.begin(), s.end());
	printtillend(s, w);

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
	string s = w;
	sort(s.begin(), s.end());
	printtillend(s, w);
	return 0;
}
