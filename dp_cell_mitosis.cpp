#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int min_cost(int n, int x, int y, int z)
{
	int dp[10] = {};
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			int op1 = dp[i - 1] + y;
			int op2 = dp[i / 2] + x;
			dp[i] = min(op1, op2);
		}
		else
		{
			int op1 = dp[i - 1] + y;
			int op2 = dp[(i + 1) / 2] + z + x;
			dp[i] = min(op1, op2);

		}
	}
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
	// int t; cin>>t; while(t--)
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	cout << min_cost(n, x, y, z);
	return 0;
}
