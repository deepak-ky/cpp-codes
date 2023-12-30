	#include<iostream>
	#include<bits/stdc++.h>
	using namespace std;
	#define mod                          1000000007
	#define varname(name)                #name
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

	const int N = 1000001;
	int dp[N];

	int main()
	{
		init();


			int n,x;
			cin >> n >> x;
			int *coins = new int[n];
			for(int i=0;i<n;i++)
			{
				cin >> coins[i];
			}


			dp[0] = 1;
			for(int i=1;i<=x;i++)
			{
				dp[i] = 0;
				for(int j=0;j<n;j++)
				{
					if((i - coins[j]) >= 0) dp[i] = (dp[i]%mod + dp[i-coins[j]]%mod)%mod;
				}
			}

			cout << dp[x];
		
		return 0;
	}
