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
		int startTime[] = {4, 2, 4, 8, 2};
		int endTime[] = {5, 5, 5, 10, 8};
		int profit[] = {1, 2, 8, 10, 4};

		int n = sizeof(endTime) / sizeof(int);

		vector<pair < int , pair<int, int> > > v;

		for (int i = 0; i < n; i++)
		{
			v.push_back({endTime[i] , {startTime[i], profit[i]}});
		}

		sort(v.begin(), v.end());

		for (auto x : v)
		{
			pair<int, int> p = x.second;
			{
				cout << p.f << " , " << x.first <<  " :  " << p.se;
			}
			cout << endl;
		}

		int max_profit[n];
		for (int i = 0; i < n; i++)
		{
			max_profit[i] = v[i].second.second;
		}



		for (int i = 1; i < n; i++)
		{
			int current_starting_time = v[i].second.first;
			int option = max_profit[i];
			for (int j = 0; j < i; j++)
			{

				int et = v[j].first;
				if (et <= current_starting_time)
				{

					option = max(option , max_profit[i] + max_profit[j]);
				}
			}
			max_profit[i] = option;

		}

		out(max_profit, n);

		int ans = max_profit[0];
		for (int i = 1; i < n; i++)
		{
			ans = max(ans , max_profit[i]);
		}

		cout << "answer here is : " << ans << endl;
	}
	return 0;
}
