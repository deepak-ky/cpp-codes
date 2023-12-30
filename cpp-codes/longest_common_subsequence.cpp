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

/*int length_lcs(string a, string b, int n, int m)
{
	if (n == 0 || m == 0)
	{
		return 0;
	}
	if (a[n - 1] == b[m - 1])
	{
		return 1 + length_lcs(a, b, n - 1, m - 1);
	}
	else return max(length_lcs(a, b, n - 1, m) , length_lcs(a, b, n, m - 1));
}*/
int length_lcs(string a, string b, int idx, int idx1 , int n, int m)
{
	if (idx >= n || idx1 >= m)
	{
		return 0;
	}
	if (a[idx] == b[idx1])
	{
		return 1 + length_lcs(a, b, idx + 1, idx1 + 1 , n, m);
	}
	else return max(length_lcs(a, b, idx + 1, idx1, n, m) , length_lcs(a, b, idx, idx1 + 1, n, m));
}

int length_lcs_bottom_up(string a, string b, int n, int m)
{
	int  dp[n + 1][m + 1];
	//memset(dp , -1 , sizeof(dp));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
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
	int n, m;
	cin >> n >> m;
	string a; string b;
	cin >> a >> b;
	cout << length_lcs(a, b, 0 , 0 , n, m);
	return 0;
}
