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

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		int dp[n][2];



		dp[0][0] = a[0];
		dp[0][1] = a[0] * a[0];

		int ans = max(dp[0][0] , dp[0][1]);

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][0] + a[i] , a[i]);

			dp[i][1] = max(dp[i - 1][1] + a[i] , max(dp[i - 1][0] + (a[i] * a[i]) , a[i] * a[i]));

			ans = max(ans , max(dp[i][0], dp[i][1]));
		}

		cout << ans << endl;




	}
	return 0;
}
