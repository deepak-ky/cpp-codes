#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printtillend(string w)
{
	cout << w << endl;

	bool val = next_permutation(w.begin(), w.end());
	if (val)
	{
		printtillend(w);
	}

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
	sort(w.begin(), w.end());
	printtillend(w);
	return 0;
}
