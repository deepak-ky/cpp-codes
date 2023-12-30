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
int lcs(string a, string b, string c)
{
	int alen = a.length();
	int blen = b.length();
	int clen = c.length();
	int dp[alen + 1][blen + 1][clen + 1];
	int ans = INT_MIN;
	for (int i = 0; i < (alen + 1); i++)
	{
		for (int j = 0; j < (blen + 1); j++)
		{
			for (int k = 0; k < (clen + 1); k++)
			{
				if (i == 0 || j == 0 || k == 0)
				{
					dp[i][j][k] = 0;
				}
				else
				{
					char ch1 = a[i - 1];
					char ch2 = b[j - 1];
					char ch3 = c[k - 1];
					if (ch1 == ch2 && ch2 == ch3)
					{
						dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];

					}
					else if (ch1 != ch2 || ch2 != ch3 || ch1 != ch3)
					{
						int op1 = dp[i - 1][j][k];
						int op2 = dp[i][j - 1][k];
						int op3 = dp[i][j][k - 1];
						dp[i][j][k] = max(op1, max(op2, op3));
					}
					ans = max(ans, dp[i][j][k]);
				}
			}

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
	/*int index = dp[alen][blen];
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
	//taking lcs of two strings at a time and then taking the lcs of those strings would not work because
	//when we are taking the lcs we are considering the LONGEST of that pair it is not necessry that common of
	//that pair would also give us the maximum length with the third string
	//Example TAB,TABEGXY,EGXYTAB the above implementation will give us the answer zero
	string a, b , c;
	cin >> a >> b >> c;
	cout << lcs(a, b, c);
	return 0;
}
