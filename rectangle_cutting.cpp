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
#define s                            second

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

int solve(int a,int b,vector<vector<int>> dp)
{


	//base case , transition jisme fail ho jaayee
	if(dp[a][b] != -1)
	{
		return dp[a][b];
	}

	if (a == b)
	{
		return dp[a][b] = 0;
	}

 		if(a == 1 || b == 1)    return dp[a][b] = (a == 1 ? b-1 : a-1);

	int ans = INT_MAX;
	for(int k=1;k<a;k++)
	{
		ans = min(ans,(1+solve(k,b,dp) + solve((a-k),b,dp)));
	}

	for(int k=1;k<b;k++)
	{
		ans = min(ans,(1+solve(a,k,dp) + solve(a,(b-k),dp)));
	}

	return dp[a][b] = ans;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int a,b;
		cin >> a >> b;

		vector<vector<int>> dp(a+1,vector<int>(b+1,-1));

		cout << solve(a,b,dp);
	}
	return 0;
}
