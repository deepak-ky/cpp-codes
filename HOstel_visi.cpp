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

int inline rock_dist(int x, int y)
{
	return pow(x, 2) + pow(y, 2);
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int q;
	cin >> q;
	int k;
	cin >> k;
	priority_queue<int> pq;
	for (int i = 0; i < q; i++)
	{
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			int x, y;
			cin >> x >> y;
			int rd = rock_dist(x, y);
			if (pq.size() >= k)
			{
				if (rd < pq.top())
				{
					pq.pop();
					pq.push(rd);
				}
			}
			else pq.push(rd);
		}
		else if (ch == 2)
		{
			cout << pq.top() << endl;
		}
	}
	return 0;
}
