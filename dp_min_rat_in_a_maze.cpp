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
int min_ways_to_reach(int maze[][4])
{
	int dp[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			dp[i][j] = 99;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i < 4; i++)
	{
		if (maze[0][i] != -1)
		{
			dp[0][i] = 1;
		}
		else break;
	}
	for (int i = 1; i < 4; i++)
	{
		if (maze[i][0] != -1)
		{
			dp[i][0] = 1;
		}
		else break;
	}
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (maze[i][j] != -1)
			{
				int op1 = 0;
				if (dp[i - 1][j] != 99)
				{
					op1 = dp[i - 1][j];
				}
				int op2 = 0;
				if (dp[i][j - 1] != 99)
				{
					op2 = dp[i][j - 1];
				}
				dp[i][j] = op1 + op2;

			}
			else
				dp[i][j] = 99;
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return dp[3][3];
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int maze[4][4] =  {{0,  0, 0, 0},
		{0, -1, 0, 0},
		{ -1, 0, 0, 0},
		{0,  0, 0, 0}
	};
	int dp[4][4];
	cout << min_ways_to_reach(maze);
	return 0;
}
