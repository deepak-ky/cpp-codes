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
		int startTime[] = {1, 4, 2, 8};
		int endTime[] = {6, 6, 8, 10};
		int profit[] = {100, 8, 4, 10};

		int n = sizeof(endTime) / sizeof(int);

		vector<pair < int , pair<int, int> > > v;

		for (int i = 0; i < n; i++)
		{
			v.push_back({endTime[i] , {startTime[i], profit[i]}});
		}

		sort(v.begin(), v.end());

		int max_profit[n];
		max_profit[0] = v[0].second.second;


		for (int i = 1; i < n; i++)
		{
			//Here I want to find a ending time , which is the largest and smaller than my
			//current starting time , beacuse that will have solution to all sub problems also
			wer(i);
			int st = v[i].second.first;

			int low = 0;
			int high = i - 1;
			int ans = -1;

			while (low <= high)
			{

				int m = low + ((high - low) / 2);
				int et = v[m].first;
				if (et <= st)
				{
					ans = m;
					low = m + 1;
				}
				else
				{
					high = m - 1;
				}

			}

			wer(ans);

			int op1 = v[i].second.second;
			if (ans != -1)
			{
				op1 = v[i].second.second + max_profit[ans];
			}

			int op2 = max_profit[i - 1];

			max_profit[i] = max(op1, op2);

			wer(max_profit[i]);
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
