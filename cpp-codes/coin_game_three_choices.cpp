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

		int x, y;
		cin >> x >> y;


		// I will define a array , which will tell me, if N number of coins are present , whether
		// that person can win or not


		bool dp[n + 1];

		dp[0] = false;
		dp[1] = true;


		for (int i = 2; i < n + 1; i++)
		{
			// I have to find just one condition , in which , if I take the coin
			// a certain number of coins , the resulting number of coins always lead to
			// a defeat for the other person

			bool will_result_in_defeat = false;

			if (dp[i - 1] == false)
			{
				will_result_in_defeat = true;
			}

			if (i >= x)
			{
				if (dp[i - x] == false)
				{
					will_result_in_defeat = true;
				}
			}


			if (i >= y)
			{
				if (dp[i - y] == false)
				{
					will_result_in_defeat = true;
				}
			}


			if (will_result_in_defeat == true)
			{
				dp[i] = true;
			}
			else dp[i] = false;

		}


		cout << dp[n] << endl;


	}
	return 0;
}
