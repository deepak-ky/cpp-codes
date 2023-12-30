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
int max_cuts(int n, int a, int b, int c)
{
	int dp[n + 1];
	dp[0] = 0;
	for (int i = 1; i < (n + 1); i++)
	{
		int op1, op2, op3;
		op1 = op2 = op3 = INT_MIN;
		if ((i - a) >= 0)
		{
			op1 = dp[i - a] + 1;
			if ( i != a && dp[i - a] == 0) //meaning this number can never be formed
				op1 = dp[i - a];
		}
		if ((i - b) >= 0)
		{
			op2 = dp[i - b] + 1;
			if ( i != b && dp[i - b] == 0) //meaning this number can never be formed
				op2 = dp[i - b];
		}
		if ((i - c) >= 0)
		{
			op3 = dp[i - c] + 1;
			if ( i != c && dp[i - c] == 0) //meaning this number can never be formed
				op3 = dp[i - c];
		}
		int op = max(op1, max(op2, op3));
		int w = 0;
		dp[i] = max(w, op);

	}
	//out(dp, n + 1);
	return dp[n];

}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << max_cuts(n, a, b, c);

	return 0;
}
