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
void heapify(vector<int> &v, int i , int size)
{
	int idx = i;
	int left = 2 * i;
	int right = left + 1;
	int last_index = size - 1;

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
		heapify(v, max_index, size);
	}

}
void build_max_heap(vector<int> &v)
{
	for (int i = v.size() - 1; i >= 1; i--)
	{
		heapify(v, i, (v.size()));
	}
}
void heap_sort(vector<int> &v)
{
	build_max_heap(v);
	int n = v.size();
	while (n > 1 /*n>2*/)
	{
		swap(v[1], v[n - 1]); //dealing with n - 1
		n--;// we are decrementing the n variable not the actual size of the vector

		heapify(v, 1, n);
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
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		v.push_back(w);
	}
	for (auto x : v)
	{
		cout << x << " ";
	}
	heap_sort(v);
	cout << endl << "After Sorting : ";
	cout << endl;

	for (auto x : v)
	{
		cout << x << " ";
	}
	return 0;
}
