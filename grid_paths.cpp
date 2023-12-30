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

int count_ways(int i,int j,int n,vector<vector<char>> grid,vector<vector<int>> &dp)
{

	if(i >= n || j >= n){
		return 0;
	}

	if(grid[i][j] == '*')
	{
		return 0;
	}

	if (i == n-1 && j == n-1)
	{

		return 1;
	}

	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}

	return dp[i][j] = (count_ways(i+1,j,n,grid,dp)%mod  + count_ways(i,j+1,n,grid,dp)%mod)%mod;
}

int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<char>> grid(n,vector<char>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
			{
				char w;
				cin >> w;
				grid[i][j] = w;
			}
		}
		if(grid[0][0] == '*') cout << 0 << endl;
		else
		{
			vector<vector<int>> dp(n,vector<int>(n,-1));
			cout <<  count_ways(0,0,n,grid,dp);
			cout << endl;
		}
	}
	return 0;
}
