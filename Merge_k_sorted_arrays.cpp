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

typedef pair<int, pair<int, int> > node;

vector<int> merge_k_sorted_arrays(vector<vector<int> > arr)
{
	vector<int> ans;
	priority_queue<node, vector<node> , greater<node> > pq;
	for (int i = 0; i < arr.size(); i++)
	{
		pq.push({arr[i][0] , {i, 0}});
	}
	while (!pq.empty())
	{
		node w = pq.top();
		int  a = w.first;
		int a1 = w.second.first;
		int a2 = w.second.second;
		ans.push_back(a);
		pq.pop();
		if (a2 + 1 < arr[a1].size())
		{
			pq.push({arr[a1][a2 + 1] , {a1, a2 + 1}});
		}

	}
	return ans;
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
	vector<vector<int> > arr {{2, 6, 12, 15}, {1, 3, 14, 20}, {3, 5, 8, 10}};
	vector<int> ans = merge_k_sorted_arrays(arr);
	for (auto x : ans)
	{
		cout << x << " ";

	}


	return 0;
}
