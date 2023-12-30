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
int min_steps_to_one(int n, int *dp)
{
	//Base Case
	if ( n == 1 ) return 0;

	//Look up
	if ( dp[n] != -1) return dp[n];

	//Recursive Case if(dp[n] is not known to us)
	int op1, op2, op3;
	op1 = op2 = op3 = INT_MAX;
	op3 = min_steps_to_one(n - 1, dp);
	if (n % 3 == 0)
	{
		op1 = min_steps_to_one(n / 3, dp);
	}
	if ( n % 2 == 0)
	{
		op2 = min_steps_to_one(n / 2, dp);
	}

	op3 = min_steps_to_one(n - 1, dp);

	int ans = min(op1, min(op2, op3)) + 1;
	return dp[n] = ans;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int dp[100];
	for (int i = 0; i < 100; i++)
	{
		dp[i] = -1;
	}

	int n;
	cin >> n;
	cout << min_steps_to_one(n, dp) << endl;


	return 0;
}
