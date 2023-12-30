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

int dp[95][3];

int cnt(int n, int a)
{
	if (n == 1 && a != 2) return 1;
	if (dp[n][a] != -1)
	{
		return dp[n][a];
	}
	if (a == 2)
	{
		return dp[n][a] = cnt(n, 0) + cnt(n, 1);
	}
	else if (a == 1)
	{
		return dp[n][a] = cnt(n - 1, 0);
	}
	//else if (a == 0)
	{
		return dp[n][a] = cnt(n - 1, 0) + cnt(n - 1, 1);
	}
}


int32_t main()
{
	init();
	memset(dp, -1, sizeof(dp));
	int t = 1;
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		cout << cnt(n, 2) << endl;

	}
	return 0;
}
