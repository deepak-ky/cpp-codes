#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
string s = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int toint(string w, int lenn)
{
	if ((lenn) == 0)
	{
		return (w[lenn] - '0');
	}
	int prevans = toint(w, lenn - 1);
	int i = w[lenn] - '0';
	return prevans * 10 + i;
}
void printpairwise(string w, int idx1, int idx, int n)
{
	//Base Case
	if (idx == n)
	{
		return;
	}

	//Rec Case
	string tt;
	while ((idx1 ) < n)
	{
		string t;

		if ((idx1 ) == (n - idx) + 1)
		{
			break;
		}

		for (int i = idx1; i < (idx1 + idx); i++)
		{
			t += w[i];
		}


		int c = toint(t, (t.length() - 1));
		c = c % 26;
		tt += s[c - 1];
		idx1 = idx1 + 1;
	}
	cout << "\nThe resultant string is : " << tt;
	printpairwise(w, 0, idx + 1, n);

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char ss[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	cout << endl << ss;
	string w;
	cin >> w;
	cout << endl << w;
	int n = w.length();
	sort(w.begin(), w.end());
	cout << endl << w;
	printpairwise(w, 0, 1 , n);
	return 0;
}
