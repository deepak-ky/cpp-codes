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

void build_segment_tree(int *a, int s, int e, int *segment_tree, int idx)
{
	if (s == e)
	{
		segment_tree[idx] = a[s];
		return;
	}

	int mid = s + ((e - s) / 2);
	build_segment_tree(a, s, mid, segment_tree, 2 * idx);
	build_segment_tree(a, mid + 1, e, segment_tree, 2 * idx + 1);
	segment_tree[idx] = min(segment_tree[2 * idx], segment_tree[2 * idx + 1]);
	return;
}

int min_element(int s, int e, int *segment_tree, int idx, int qs, int qe)
{
	if (qs <= s && qe >= e)
	{
		return segment_tree[idx] % mod;
	}
	if (e < qs || s > qe)
	{
		return INT_MAX;
	}
	int mid = s + ((e - s) / 2);
	int op1 = min_element(s, mid, segment_tree, 2 * idx, qs, qe);
	int op2 = min_element(mid + 1, e, segment_tree, 2 * idx + 1, qs, qe);
	return min(op1, op2);
}

void segment_tree_update(int *segment_tree, int s, int e, int idx, int k, int diff)
{
	if (s == k && e == k)
	{
		segment_tree[idx] += diff;

		return;
	}
	if (e < k || s > k)
	{
		return;
	}
	else
	{
		int mid = s + ((e - s) / 2);
		segment_tree_update(segment_tree, s, mid, 2 * idx, k, diff);
		segment_tree_update(segment_tree, mid + 1, e, 2 * idx + 1, k, diff);
		segment_tree[idx] = min(segment_tree[2 * idx], segment_tree[2 * idx + 1]);
		return;
	}
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
		int q;
		cin >> q;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int *segment_tree = new int[4 * n + 1];
		build_segment_tree(a, 0, n - 1, segment_tree, 1);


		while (q--)
		{


			int query_type;
			int v1;
			int v2;
			cin >> query_type >> v1 >> v2;

			if (query_type == 1)
			{
				cout  << min_element(0, n - 1, segment_tree, 1, v1 - 1, v2 - 1) << endl;
			}
			else
			{

				segment_tree_update(segment_tree, 0, n - 1, 1, v1 - 1, v2);
			}
		}

	}

	return 0;
}
