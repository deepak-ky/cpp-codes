#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}



int l_c_substr(string a, string b, int n, int m)
{
	int dp[n + 1][m + 1];
	memset(dp, -1, sizeof(dp));
	int cnt = 0;
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				cnt = max(cnt, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	return cnt;
}


int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		int n1 = a.length();
		int n2 = b.length();
		int len = l_c_substr(a, b, n1, n2);
		cout << abs(len - n1) + abs(len - n2) << endl;
	}
	return 0;
}
