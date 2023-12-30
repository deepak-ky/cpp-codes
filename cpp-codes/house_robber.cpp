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

int find_max_sum(int i, bool prev_taken, int *a, int n, int *dp)
{
	if (i == n)
	{
		return 0;
	}
	if (prev_taken)
	{
		return find_max_sum(i + 1, false, a, n, dp);
	}

	if (dp[i] != -1)
	{
		return dp[i];
	}

	int op1 = a[i]  + find_max_sum(i + 1, true, a, n, dp);
	int op2 = find_max_sum(i + 1, false, a, n, dp);

	dp[i] = max(op1, op2);
	return dp[i];
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
		int *dp = new int[n];
		for (int i = 0; i < n; i++)
		{
			dp[i] = -1;
		}


		int ans = find_max_sum(0, false, a, n, dp);
		cout << ans << endl;
	}
	return 0;
}
