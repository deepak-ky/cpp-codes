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
int dp[2000007][2];
int cal_skip_score(int idx, int turn , int *a, int n)
{
	if (idx >= n)
	{
		return 0;
	}
	if (dp[idx][turn] != -1)
	{
		return dp[idx][turn];
	}
	if (turn == 0) // My -> turn
	{
		int ans = INT_MAX;
		//defeat one boss
		int op1 = min(ans, cal_skip_score(idx + 1, 1, a, n));
		//defeat the next two bosses
		int op2 = cal_skip_score(idx + 2, 1, a, n);

		ans = min(op1, op2);
		return dp[idx][turn] = ans;
	}
	else if (turn == 1)
	{
		int ans = INT_MAX;
		//defeat one boss
		ans = min(ans, a[idx] + cal_skip_score(idx + 1, 0, a, n));
		//defeat the next two bosses
		if (idx + 1 < n)
			ans = min(ans, a[idx] + a[idx + 1] + cal_skip_score(idx + 2, 0, a, n));
		return dp[idx][turn] = ans;

	}
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		memset(dp, -1, sizeof(dp));
		//0 -> my chance
		//1 -> my chance
		//If I start from here with this turn , what will be my answer
		int w = cal_skip_score(0, 1, a, n);
		cout << w << endl;

	}

	return 0;
}
