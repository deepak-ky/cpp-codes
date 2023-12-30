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
int optimal_game(int a[], int i, int j, int dp[][35])
{
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int op1 = a[i] + min(optimal_game(a, i + 2, j, dp), optimal_game(a, i + 1, j - 1, dp));
	int op2 = a[j] + min(optimal_game(a, i, j - 2, dp), optimal_game(a, i + 1, j - 1, dp));
	int ans = max(op1, op2);
	return dp[i][j] = ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int dp[35][35];
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 35; j++)
		{
			dp[i][j] = -1;
		}
	}
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	cout << optimal_game(a, 0, n - 1, dp);

	return 0;
}
