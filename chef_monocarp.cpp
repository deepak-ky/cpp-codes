#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
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

int dp[202][407];

int solve(int *a, int n, int idx, int curr_time)
{
	if (idx == n)
	{
		return 0;
	}
	if (dp[idx][curr_time] != -1)
	{
		return dp[idx][curr_time];
	}

	int ans = INT_MAX;

	for (int i = curr_time ; i <= max(curr_time, a[idx]) ; i++)
	{
		ans = min ( ans, abs(i - a[idx]) + solve(a, n, idx + 1, i + 1));
	}

	return  dp[idx][curr_time] = ans;

	//how do you initialize a = 5 ; or 5 = a; unknown = known, that is why it
	//shoud be dp[idx][curr_time] = ans and not ans = dp[idx][curr_time];

}

int32_t main()
{
	init();
	test
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i]; 22
		}
		sort(a, a + n);
		memset(dp, -1, sizeof(dp));
		cout << solve(a, n, 0, 1);
		cout << endl;
	}


	return 0;
}
