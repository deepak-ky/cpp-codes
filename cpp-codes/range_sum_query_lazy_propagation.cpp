#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=1;i<n;i++) cout<<a[i]<<" "; cout<<endl
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

void buildTree(int *a, int s, int e, int *segment_tree, int idx)
{
	if (s == e)
	{
		segment_tree[idx] += a[s];
		return;
	}
	int mid = s + ((e - s) / 2);
	buildTree(a, s, mid, segment_tree, 2 * idx);
	buildTree(a, mid + 1, e, segment_tree, 2 * idx + 1);
	segment_tree[idx] = segment_tree[2 * idx] + segment_tree[2 * idx + 1];
	return;
}

void range_update_lazy(int *segment_tree, int s, int e, int idx, int *lazy_value, int qs, int qe, int diff)
{
	//Whenever I am at a node , I will resolve it
	int w = lazy_value[idx];
	lazy_value[idx] -= w;
	segment_tree[idx] += w * (e - s + 1);
	if (s != e)
	{
		lazy_value[2 * idx] += w;
		lazy_value[2 * idx + 1] += w;
	}

	if (e < qs || s > qe)
	{
		return;
	}

	if (qs <= s && qe >= e)
	{
		segment_tree[idx] += (e - s + 1) * diff;
		if (s != e)
		{
			lazy_value[2 * idx] += diff;
			lazy_value[2 * idx + 1] += diff;
		}
		return;
	}

	int mid = s + ((e - s) / 2);
	range_update_lazy(segment_tree, s, mid, 2 * idx, lazy_value, qs, qe, diff);
	range_update_lazy(segment_tree, mid + 1, e, 2 * idx + 1, lazy_value, qs, qe, diff);
	segment_tree[idx] = segment_tree[2 * idx] + segment_tree[2 * idx + 1];
	return;
}

int range_sum_lazy(int *segment_tree, int s, int e, int idx, int *lazy_value, int qs, int qe)
{

	//Whenever I am at a node , I will resolve it
	int w = lazy_value[idx];
	lazy_value[idx] -= w;
	segment_tree[idx] += w * (e - s + 1);
	if (s != e)
	{
		lazy_value[2 * idx] += w;
		lazy_value[2 * idx + 1] += w;
	}
	if (e < qs || s > qe)
	{
		return 0;
	}
	if (qs <= s && qe >= e)
	{
		return segment_tree[idx];
	}
	int mid = s + ((e - s) / 2);
	int op1 = range_sum_lazy(segment_tree, s, mid, 2 * idx, lazy_value, qs, qe);
	int op2 = range_sum_lazy(segment_tree, mid + 1, e, 2 * idx + 1, lazy_value, qs, qe);
	return op1 + op2;

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
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int *segment_tree = new int[4 * n + 1];
		int *lazy_value = new int[4 * n + 1] {0};
		buildTree(a, 0, n - 1, segment_tree, 1);
		out(segment_tree, 14);
		out(lazy_value, 14);


		int qs = 0;
		int qe = 2;
		int diff = 10;
		//range_update_lazy(segment_tree, 0, n - 1, 1, lazy_value, qs, qe, diff);
		out(segment_tree, 14);
		out(lazy_value, 14);


		qs = 1;
		qe = 3;
		cout << range_sum_lazy(segment_tree, 0, n - 1, 1, lazy_value, qs, qe);
		qs = 1;
		qe = 5;
		cout << endl;
		diff = 10;
		range_update_lazy(segment_tree, 0, n - 1, 1, lazy_value, qs, qe, diff);
		qe = 3;
		cout << range_sum_lazy(segment_tree, 0, n - 1, 1, lazy_value, qs, qe);



	}
	return 0;
}
