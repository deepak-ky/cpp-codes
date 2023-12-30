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

const int N = 1000005;
int dp[N];

int find(int n)
{
	if(n < 0)
	{
		return 0;
	}

	if(dp[n] != -1)
	{
		return dp[n];
	}

	dp[n] = (find(n-1)%mod + find(n-2)%mod + find(n-3)%mod + find(n-4)%mod + find(n-5)%mod + find(n-6)%mod)%mod;
	return dp[n];
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
		memset(dp,-1,sizeof(dp));
		dp[0] = 1;
		cout << find(n);
		

	}
	return 0;
}
