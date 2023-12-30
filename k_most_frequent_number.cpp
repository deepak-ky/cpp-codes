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
typedef pair<int, int> node;
class node_compare
{
public:
	bool operator()(node p1, node p2)
	{
		if (p1.second != p2.second)
			return p1.second < p2.second;
		else return p1.first > p2.first;
	}

};
void map_to_pq(map<int, int> &mp, priority_queue<node, vector<node>, node_compare > &pq)
{
	while (!pq.empty())
	{
		pq.pop();
	}

	for (auto x : mp)
	{
		pq.push({x.first, x.second});
	}
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
	test
	{
		priority_queue<node, vector<node>, node_compare > pq;
		map<int, int> mp;
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			int q = k;
			int w;
			cin >> w;
			mp[w]++;
			map_to_pq(mp, pq);
			while (!pq.empty() && q > 0)
			{
				//cout << "here";
				node w = pq.top();
				cout << w.first << " ";
				pq.pop();
				q--;
			}
			// cout << "\nMap now \n";
			// for (auto x : mp)
			// {
			// 	cout << x.first << " " << x.second << endl;
			// }
			// cout << "\nPriority Queue now : ";
			// while (!pq.empty())
			// {
			// 	node x = pq.top();
			// 	cout << x.first << " " << x.second << endl;
			// 	pq.pop();

			// }
			//cout << endl;
		}
		cout << endl;
	}
	return 0;
}
