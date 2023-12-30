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

const int N = 1005;
int dp[N];

void call()
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 3; i <= N; i++)
	{

		dp[i] += dp[i - 3];
	}
	for (int i = 5; i <= N; i++)
	{

		dp[i] += dp[i - 5];
	}
	for (int i = 10; i <= N; i++)
	{

		dp[i] += dp[i - 10];
	}

}



int32_t main()
{
	init();
	int t = 1;
	call();
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		cout << dp[n] << endl;


	}
	return 0;
}
