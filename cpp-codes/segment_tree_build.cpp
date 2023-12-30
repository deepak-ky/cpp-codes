#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout/*<<"\n"*/<<varname(x)<<" here : "<<x<<"\n"
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

void  build_tree(int *a, int s, int e, int *segment_tree, int index)
{

	//base case
	if (s == e)
	{
		segment_tree[index] = a[s];
		return;
	}

	//recursive case
	int mid = s + ((e - s) / 2);
	build_tree(a, s, mid, segment_tree, 2 * index);
	build_tree(a, mid + 1, e, segment_tree, 2 * index + 1);
	segment_tree[index] = min(segment_tree[2 * index], segment_tree[2 * index + 1]);
	return;



}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = { 1, 3, 2, -5, 6, 4};
		int n = sizeof(a) / sizeof(int);

		int *segment_tree = new int[4 * n + 1];
		for (int i = 0; i < n; i++)
		{
			segment_tree[i] = INT_MIN;
		}
		build_tree(a, 0, n - 1, segment_tree, 1);


		for (int i = 1; i < (4 * n + 1); i++)
		{
			cout << segment_tree[i] << " ";
		}
		cout << endl;
		cout << segment_tree[1] << endl;

	}
	return 0;
}
