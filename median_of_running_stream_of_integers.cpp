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
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		v.push_back(w);
	}
	vector<float> ans;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int> , greater<int> > min_heap;
	float current_median = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Medain now : " << current_median << endl;
		//1. Both the heaps have equal sizes
		if (max_heap.size()  == min_heap.size())
		{
			if (v[i] < current_median)
			{
				max_heap.push(v[i]);
				current_median = max_heap.top();
			}
			else if (v[i] >= current_median)
			{
				min_heap.push(v[i]);
				current_median = min_heap.top();
			}
			ans.push_back(current_median);
		}
		//2.Number of elements in the max heap are greater
		else if (max_heap.size() > min_heap.size())
		{
			if (v[i] < current_median)
			{
				int w = max_heap.top();
				max_heap.pop();
				min_heap.push(w);
				max_heap.push(v[i]);
			}
			else if (v[i] >= current_median)
			{
				min_heap.push(v[i]);
			}
			float z =  min_heap.top() + max_heap.top();
			current_median = z / 2;
			ans.push_back(current_median);
		}
		//3 . NUmber of elements in the min heap are greater
		else if (max_heap.size() < min_heap.size())
		{
			if (v[i] < current_median)
			{
				max_heap.push(v[i]);
			}
			else if (v[i] >= current_median)
			{
				int w = min_heap.top();
				min_heap.pop();
				max_heap.push(w);
				min_heap.push(v[i]);
			}
			float z =  min_heap.top() + max_heap.top();
			current_median = z / 2;
			ans.push_back(current_median);
		}
	}
	//cout << "Median Array : \n";
	for (auto x  : ans)
	{
		cout << x << " ";
	}

	return 0;
}
