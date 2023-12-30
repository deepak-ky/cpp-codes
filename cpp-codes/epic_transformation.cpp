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
	cin >> t;
	while (t--)
	{

		int n;
		cin >> n;
		int *a = new int[n];
		/*unordered_*/map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[a[i]]++;
		}

		priority_queue<int> pq;
		for (auto x : mp)
		{
			pq.push(x.second);
		}


		while (pq.size() >= 2)
		{
			int m1 = pq.top();
			pq.pop();
			int m2 = pq.top();
			pq.pop();
			m1--;
			m2--;
			if (m1 > 0) pq.push(m1);
			if (m2 > 0) pq.push(m2);
		}


		if (pq.size() == 1)
		{
			int m1 = pq.top();
			cout << m1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}


	}
	return 0;
}
