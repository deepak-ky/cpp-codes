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

void build_tree(int *a, int s, int e, int* segment_tree, int idx)
{
	if (s == e)
	{
		segment_tree[idx] = a[s];
		return;
	}

	int mid = s + ((e - s) / 2);
	build_tree(a, s, mid, segment_tree, 2 * idx);
	build_tree(a, mid + 1, e, segment_tree, 2 * idx + 1);
	segment_tree[idx] = min(segment_tree[2 * idx], segment_tree[2 * idx + 1]);
	return;
}

/*int min_element(int s, int e, int *segment_tree, int idx, int qs, int qe)
{
	int mid = s + ((e - s) / 2);
	//Complete Overlap
	if (qs <= s && qe >= e)
	{
		return segment_tree[idx];
	}
	//Partial overlap - Case - 1
	else if (qe >= s && qs < s)
	{
		int op1 = min_element(s, mid, segment_tree, 2 * idx, qs, qe);
		int op2 = min_element(mid + 1, e, segment_tree, 2 * idx + 1, qs, qe);
		return min(op1, op2);
	}
	//Partial overlap - Case - 2
	else if (qs <= e && qe > e)
	{
		int op1 = min_element(s, mid, segment_tree, 2 * idx, qs, qe);
		int op2 = min_element(mid + 1, e, segment_tree, 2 * idx + 1, qs, qe);
		return min(op1, op2);
	}
	//Partial overlap - Case - 3
	else if (qs >= s && qe <= e)
	{
		int op1 = min_element(s, mid, segment_tree, 2 * idx, qs, qe);
		int op2 = min_element(mid + 1, e, segment_tree, 2 * idx + 1, qs, qe);
		return min(op1, op2);
	}
	//No Overlap
	else if (qe < s || qs > e)
	{
		return INT_MAX;
	}
}*/


int min_element(int s, int e, int *segment_tree, int idx, int qs, int qe)
{
	//Complete Overlap
	if (qs <= s && qe >= e)
	{
		return segment_tree[idx];
	}

	//No Overlap

	if (qe < s || qs > e)
	{
		return INT_MAX;
	}
	//rest all cases that remain are cases of partial overlap
	int mid = s + ((e - s) / 2);

	int op1 = min_element(s, mid, segment_tree, 2 * idx, qs, qe);
	int op2 = min_element(mid + 1, e, segment_tree, 2 * idx + 1, qs, qe);
	return min(op1, op2);


}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = {1, 3, 2, -5, 6, 4};
		int n = sizeof(a) / sizeof(int);
		int *segment_tree = new int[4 * n + 1];
		build_tree(a, 0, n - 1, segment_tree, 1);
		out(segment_tree, 16);

		int qs, qe;
		qs = 0;
		qe = 2;

		cout << min_element( 0, n - 1, segment_tree, 1, qs, qe);




	}
	return 0;
}
