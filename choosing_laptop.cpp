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
class laptop
{
public:
	int speed;
	int ram;
	int hdd;
	int cost;
	bool isoutdated = false;
};
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	laptop l[n];
	for (int i = 0; i < n; i++)
	{
		cin >> l[i].speed >> l[i].ram >> l[i].hdd >> l[i].cost;
	}
	for (int i = 0; i < (n); i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (l[j].speed != -1)
			{
				if ((l[i].speed < l[j].speed) && (l[i].ram < l[j].ram) && (l[i].hdd < l[j].hdd))
				{
					l[i].speed = -1;
					l[i].ram  = -1;
					l[i].hdd = -1;
					break;
				}
			}

		}

	}
	int best_idx = -1;
	int min_cost = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if ((l[i].speed != -1))
		{
			if (l[i].cost <= min_cost)
			{
				min_cost = l[i].cost;
				best_idx = i;
			}
		}

	}
	cout << best_idx + 1;

	return 0;
}

