#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
void lcs(string a, string b)
{
	int alen = a.length();
	int blen = b.length();
	unordered_map<char, bool> mp;
	int dp[alen + 1][blen + 1];
	for (int i = 0; i < (alen + 1); i++) dp[i][0] = 0;
	for (int i = 0; i < (blen + 1); i++) dp[0][i] = 0;
	int ans = INT_MIN;
	for (int i = 1; i < (alen + 1); i++)
	{
		for (int j = 1; j < (blen + 1); j++)
		{
			char ch1 = a[i - 1];
			char ch2 = b[j - 1];
			if (ch1 == ch2)
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];

			}
			else if (ch1 != ch2)
			{
				int op1 = dp[i - 1][j];
				int op2 = dp[i][j - 1];
				dp[i][j] = max(op1, op2);
			}
			ans = max(ans, dp[i][j]);

		}
	}

	/*	for (int i = 0; i < (alen + 1); i++)
		{
			for (int j = 0; j < (blen + 1); j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
	int index = dp[alen][blen];
	char sub_sequence[index + 1];
	sub_sequence[index] = '\0';
	int i = alen; int j = blen;
	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			sub_sequence[index - 1] = a[i - 1];
			i--;
			j--;
			index--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else j--;
	}
	cout << sub_sequence;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string a, b;
	cin >> a >> b;
	lcs(a, b);
	return 0;
}
