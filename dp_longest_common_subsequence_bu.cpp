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
int lcs(string s, string w)
{
	int dp[10][10] = {};
	int slen = s.length();
	int wlen = w.length();
	int ans = INT_MIN;
	for (int i = 1; i < wlen + 1; i++)
	{
		for (int j = 1; j < slen + 1; j++)
		{
			char ch1 = w[i - 1];
			char ch2 = s[j - 1];
			if (ch1 == ch2)
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else if (ch1 != ch2)
			{
				int op1 = dp[i - 1][j];
				int op2 = dp[i][j - 1];
				dp[i][j] = max(op1, op2);
			}
			ans = max(ans, dp[i][j]);       //need not to take max here because even if ans = dp[i][j] it will return 4 here only because it will be the last value which is initialise the bottom right of the table which is in fact the answer

		}

	}
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	return ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string s, w;
	cin >> s >> w;
	cout << lcs(s, w);
	return 0;
}
