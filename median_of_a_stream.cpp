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



int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int w;
	cin >> w;
	int cur_mean = w;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
	max_heap.push(cur_mean);
	cout << cur_mean << " ";
	for (int i = 1; i < n; i++)
	{
		int a;
		cin >> a;
		if (min_heap.size() > max_heap.size())
		{
			if (a > cur_mean)
			{
				int w = min_heap.top();
				min_heap.pop();
				max_heap.push(w);
				min_heap.push(a);
			}
			else if (a <= cur_mean)
			{
				max_heap.push(a);
			}
			cur_mean = (min_heap.top() + max_heap.top()) / 2;
			cout << cur_mean << " ";
		}
		else if (min_heap.size() < max_heap.size())
		{
			if (a <= cur_mean)
			{
				int w = max_heap.top();
				max_heap.pop();
				min_heap.push(w);
				max_heap.push(a);
			}
			else if (a > cur_mean)
			{
				min_heap.push(a);
			}
			cur_mean = (min_heap.top() + max_heap.top()) / 2;
			cout << cur_mean << " ";
		}
		else if (min_heap.size() == max_heap.size())
		{
			if (a <= cur_mean)
			{
				max_heap.push(a);
				cur_mean = max_heap.top();
				cout << cur_mean << " ";
			}
			else if (a > cur_mean)
			{
				min_heap.push(a);
				cur_mean = min_heap.top();
				cout << cur_mean << " ";
			}
		}
	}
	return 0;
}
