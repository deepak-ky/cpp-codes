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
		vector<int> pre;
		pre.push_back(0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int k;
		cin >> k;

		for (int i = 0; i < n; i++)
		{
			int w = a[i] + pre[i];
			pre.push_back(w);
		}


		vector<int> all_subarraysum;

		for (int j = 1; j < pre.size(); j++)
		{
			for (int i = 1; i <= j; i++)
			{
				all_subarraysum.push_back(pre[j] - pre[i - 1]);
			}
		}


		priority_queue<int, vector<int> , greater<int>> pq;

		for (int i = 0; i < all_subarraysum.size(); i++)
		{
			if (pq.size() < k) pq.push(all_subarraysum[i]);
			else
			{
				if (all_subarraysum[i] > pq.top())
				{
					pq.pop();
					pq.push(all_subarraysum[i]);
				}
			}
		}

		cout << pq.top() << endl;


	}


	return 0;
}
