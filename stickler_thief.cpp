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

const int n = 10004;
int dp[n][2];

int solve(int *a, int i, int n, bool previous_house_loot)
{
	if (i >= n)
	{
		return 0;
	}

	//he has two options whether the can loot the current house or he cannot loot

	if (dp[i][previous_house_loot] != -1)
	{
		return dp[i][previous_house_loot];
	}

	if (previous_house_loot == false)
	{

		int op1 =  a[i] + solve(a, i + 1, n, true);

		int op2 =  solve(a, i + 1, n, false);

		return dp[i][previous_house_loot] =   max(op1, op2);

	}
	else
	{
		return dp[i][previous_house_loot] = solve(a, i + 1, n, false);
	}

}




int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		memset(dp, -1, sizeof(dp));

		cout << solve(a, 0, n, false);



	}
	return 0;
}
