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
		string s;
		cin >> s;
		int k;
		cin >> k;

		unordered_map<char, int> mp;
		for (auto x : s)   mp[x]++;


		priority_queue<int> pq;

		for (auto x : mp)
		{
			//wer(x.second);
			pq.push(x.second);
		}

		while (k != 0 && !pq.empty())
		{
			int a = pq.top();
			pq.pop();
			a--;
			k--;

			pq.push(a);


		}


		int ans = 0;

		while (!pq.empty())
		{

			//cout << pq.top () << endl;
			ans += (pq.top() * pq.top());
			pq.pop();
		}


		cout << ans << " ";
	}
	return 0;
}
