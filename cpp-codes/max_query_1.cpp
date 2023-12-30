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
void build_tree(int *a, int s, int e, int *segment_tree, int idx)
{
	if (s == e)
	{
		segment_tree[idx] = a[s];
		return;
	}
	int mid = s + ((e - s) / 2);
	build_tree(a, s, mid, segment_tree, 2 * idx);
	build_tree(a, mid + 1, e, segment_tree, 2 * idx + 1);
	segment_tree[idx] = min(segment_tree[2 * idx] , segment_tree[2 * idx + 1]);
	return;
}

int elements_greater(int *segment_tree, int s, int e, int idx, int qs, int qe, int k)
{
	//First and foremeost case every time should be the out of bound condition
	if (e < qs || s > qe)
	{
		return 0;
	}
	if (s == e)
	{
		if (segment_tree[idx] >= k)
		{
			return 1;
		}
		else return 0;
	}

	//Complete Overlap and the minimum element in the given range is greater
	//my k
	if (qs <= s && qe >= e && segment_tree[idx] >= k)
	{
		return e - s + 1;
	}
	//The case of no overlap


	int mid = s + ((e - s) / 2);
	int op1 = elements_greater(segment_tree, s, mid, 2 * idx, qs, qe, k);
	int op2 = elements_greater(segment_tree, mid + 1, e, 2 * idx + 1, qs, qe, k);
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
		build_tree(a, 0, n - 1, segment_tree, 1);
		int q;
		cin >> q;

		while (q--)
		{
			int qs, qe, k;
			cin >> qs >> qe >> k;
			cout << elements_greater(segment_tree, 0, n - 1, 1, qs - 1, qe - 1, k) << endl;
		}

	}
	return 0;
}
