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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = {100, 1000, 100, 1000, 1};

		int n = sizeof(a) / sizeof(int);

		int dp[n];

		dp[0] = a[0];
		dp[1] = a[0] + a[1];
		dp[2] = max((a[0] + a[1]), max((a[1] + a[2]), a[0] + a[2]));
		for (int i = 3; i < n; i++)
		{
			int opt1 = dp[i - 3] + a[i - 1] + a[i];
			int opt2 = dp[i - 2] + a[i];
			int opt3 = dp[i - 1];

			dp[i] = max(opt1, max(opt2, opt3));
		}



		out(dp, n);


		cout << endl << "Ans : " << dp[n - 1];


	}
	return 0;
}
