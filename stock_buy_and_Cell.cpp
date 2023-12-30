#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n;
		cin >> n;
		int a[n];
		asdf(a, n);

		int buy_day = -1;
		int sell_day = -1;

		int total_profit = 0;
		bool flag = 1;
		bool flag1 = 0;
		for (int i = 0; i < n - 1; i++)
		{
			//we are searching for buy day , need the price of stocks to be minimum
			if (flag)
			{
				if (a[i] < a[i + 1])
				{
					buy_day = i;
					flag1 = 1;
					flag  = 0;
				}
			}
			//we are searching for sell day. need the price of the stock to be the maximum
			if (flag1)
			{
				if (a[i] > a[i + 1])
				{
					sell_day = i;
					cout << "(" << buy_day << " " << sell_day << ") ";
					flag = 1;
					flag1 = 0;
				}
			}

		}
		if (flag == 0 && flag1 == 1)
		{
			//last day has a greater value so we
			//also
			sell_day = n - 1;
			cout << "(" << buy_day << " " << sell_day << ") ";
		}
		if (buy_day == -1 || sell_day == -1)
		{
			cout << "No Profit" ;
		}
		cout << endl;
	}

	return 0;
}
