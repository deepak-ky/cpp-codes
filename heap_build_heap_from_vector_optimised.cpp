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
void heapify(vector<int> &v, int i)
{
	int idx = i;
	int left = 2 * i;
	int right = left + 1;
	int last_index = v.size() - 1;

	int max_index = idx;

	if (left <= last_index && v[left] > v[idx])
	{
		max_index = left;
	}
	if (right <= last_index && v[right] > v[max_index])
	{
		max_index = right;
	}

	if (max_index != idx)
	{
		swap(v[idx], v[max_index]);
		heapify(v, max_index);
	}

}
void build_max_heap(vector<int> &v)
{
	int n = v.size();
	for (int i = (n - 1) / 2; i >= 1; i--)
	{
		//wer(i);
		heapify(v, i);
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
	vector<int> v = { -1, 10, 25, 5, 6, 1, 8, 9, 4};
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
	build_max_heap(v);
	for (auto x : v)
	{
		cout << x << " ";
	}
	return 0;
}
