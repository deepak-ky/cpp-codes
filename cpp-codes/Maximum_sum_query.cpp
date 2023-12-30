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

void buildTree(int *a, int s, int e, int *segment_tree, int idx)
{
	if (s == e)
	{
		segment_tree[idx] = a[s];
		return;
	}
	int mid = s + ((e - s) / 2);
	buildTree(a, s, mid, segment_tree, 2 * idx);
	buildTree(a, mid + 1, e, segment_tree, 2 * idx + 1);
	segment_tree[idx] = max(segment_tree[2 * idx] , segment_tree[2 * idx + 1]);
	segment_tree[idx] = max(segment_tree[2 * idx] + segment_tree[2 * idx + 1] , segment_tree[idx]);
	return;
}

int max_element(int *segment_tree, int s, int e, int idx, int qs, int qe)
{
	if (e < qs || s > qe)
	{
		return 0;
	}
	if (qs <= s && qe >= e)
	{
		return segment_tree[idx];
	}
	int mid = s + ((e - s) / 2);
	int op1 = max_element(segment_tree, s, mid, 2 * idx, qs, qe);
	int op2 = max_element(segment_tree, mid + 1, e, 2 * idx + 1, qs, qe);
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
		buildTree(a, 0, n - 1, segment_tree, 1);
		int q;
		cin >> q;
		while (q--)
		{
			int qs, qe;
			cin >> qs >> qe;
			cout << max_element(segment_tree, 0, n - 1, 1, qs - 1, qe - 1)  << endl;
		}

	}
	return 0;
}
