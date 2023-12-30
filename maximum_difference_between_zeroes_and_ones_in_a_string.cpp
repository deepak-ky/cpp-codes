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

int find_max_contigous_sum(int *a, int n)
{
	int dp[n];

	dp[0] = a[0];

	int ans = a[0];

	for (int i = 1; i < n; i++)
	{
		int opt1 = a[i];
		int opt2 = dp[i - 1] + a[i];

		dp[i] = max(opt1, opt2);

		ans = max(ans, dp[i]);
	}

	// out(a, n);

	// out(dp, n);

	return ans;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s;
		cin >> s;

		int n = s.length();

		int a[n];
		int b[n];

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
			{
				a[i] = -1;
				b[i] = 1;
			}
			else
			{
				a[i] = 1;
				b[i] = -1;
			}
		}


		int opt1 = find_max_contigous_sum(a, n);
		int opt2 = find_max_contigous_sum(b, n);

		cout << max(opt1, opt2);
	}
	return 0;
}
