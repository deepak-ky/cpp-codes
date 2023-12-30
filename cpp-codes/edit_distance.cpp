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

int edit_distance(string a, string b)
{
	int n = a.length();
	int m = b.length();

	//NEED TO CONVERT A FROM B
	//A IS ON THE X AXIS AND B IS ON THE Y AXIS
	int dp[n + 1][m + 1];
	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = i;
	}

	for (int i = 0; i < m + 1; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				int temp = min(dp[i - 1][j], dp[i][j - 1]);
				temp = min(temp, dp[i - 1][j - 1]);
				dp[i][j] = temp + 1;
			}
		}
	}
	return dp[n][m];
}


int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string s1;
	string s2;
	cin >> s1 >> s2;
	//convert s2 from s1;
	//send s2 first;
	cout << edit_distance(s2, s1);
	return 0;
}
