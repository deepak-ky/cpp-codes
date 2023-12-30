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
		int  curr_fuel = 0;
		int cost[n];
		int minPetrolReq[n];
		for (int i = 0; i < n; i++)
		{
			cin >> cost[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> minPetrolReq[i];
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		int total_cost = 0;
		int i = 0;
		while (i < n)
		{
			pq.push(cost[i]);
			int extra_fuel = minPetrolReq[i];
			int w = extra_fuel * pq.top();
			total_cost += w;
			i++;
		}
		cout << total_cost << endl;

	}
	return 0;
}
