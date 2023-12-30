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

const int N = 1005;
int dp[N][N];

int cnt_palindromic_subsequence(string a, int i, int j)
{

	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}

	if (i > j)
	{

		return dp[i][j] = 0;
	}
	if (i == j)
	{
		return dp[i][j] = 1;
	}

	int ans;

	if (a[i] == a[j])
	{
		ans = cnt_palindromic_subsequence(a, i, j - 1) % mod + cnt_palindromic_subsequence(a, i + 1, j) % mod + 1;
		ans %= mod;
	}
	else
	{
		ans = cnt_palindromic_subsequence(a, i, j - 1) % mod + cnt_palindromic_subsequence(a, i + 1, j) % mod - cnt_palindromic_subsequence(a, i + 1, j - 1) % mod;
		ans %= mod;

	}
	return dp[i][j] = ans;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		memset(dp, -1, sizeof(dp));

		string a;
		cin >> a;

		int n = a.length();

		cout << cnt_palindromic_subsequence(a, 0, n - 1);

	}
	return 0;
}
