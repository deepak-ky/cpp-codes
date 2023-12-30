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

const int y = 105;
int dp[y][y];

bool is_interleaved(string a, string b, string c, int idx, int idx1, int idx2, int n, int n1, int n2)
{
	if (dp[idx1][idx2] != -1)
	{
		return dp[idx1][idx2];
	}
	else
	{
		//when to return true
		if (idx1 == n1 && idx2 == n2)
		{
			return dp[idx1][idx2] = true;
		}
		if (idx == n)
		{
			return dp[idx1][idx2] = false;
		}

		if (idx1 == n1)
		{
			if (c[idx2] == a[idx])
			{
				return dp[idx1][idx2] = is_interleaved(a, b, c, idx + 1, idx1, idx2 + 1, n, n1, n2);
			}
			else return dp[idx1][idx2] = false;
		}
		else if (idx2 == n2)
		{
			if (b[idx1] == a[idx])
			{
				return dp[idx1][idx2] = is_interleaved(a, b, c, idx + 1, idx1 + 1, idx2, n, n1, n2);
			}
			else return dp[idx1][idx2] = false;
		}
		else if (b[idx1] != a[idx] && c[idx2] != a[idx])
		{
			return dp[idx1][idx2] = false;
		}
		else if (b[idx1] == a[idx] && c[idx2] == a[idx])
		{
			bool flag1 = is_interleaved(a, b, c, idx + 1, idx1 + 1, idx2, n, n1, n2);
			bool flag2 = is_interleaved(a, b, c, idx + 1, idx1, idx2 + 1, n, n1, n2);
			return dp[idx1][idx2] = (flag1 | flag2);
		}
		else if (b[idx1] == a[idx])
		{
			return dp[idx1][idx2] = is_interleaved(a, b, c, idx + 1, idx1 + 1, idx2, n, n1, n2);
		}
		else if (c[idx2] == a[idx])
		{
			return dp[idx1][idx2] = is_interleaved(a, b, c, idx + 1, idx1, idx2 + 1, n, n1, n2);
		}

		return dp[idx1][idx2] = false;
	}

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		memset(dp, -1, sizeof(dp));

		string a, b, c;
		cin >> a >> b >> c;

		int n = a.length();
		int n1 = b.length();
		int n2 = c.length();

		if (is_interleaved(a, b, c, 0, 0, 0, n, n1, n2))
		{
			yes;
		}
		else no;
	}
	return 0;
}
