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

void heapify(int idx, int *a, int n)
{
	int current_idx = idx;
	int left_child_idx = idx * 2;
	int right_child_idx = idx * 2 + 1;

	int max_index = current_idx;

	if (left_child_idx <= (n - 1) && a[left_child_idx] > a[max_index])
	{
		max_index = left_child_idx;
	}

	if (right_child_idx <= (n - 1) && a[right_child_idx] > a[max_index])
	{
		max_index = right_child_idx;
	}

	if (max_index != current_idx)
	{
		swap(a[current_idx], a[max_index]);
		heapify(max_index, a, n);
	}


}

void build_max_heap(int *a, int n)
{
	for (int i = ((n - 1) / 2); i >= 1; i--)
	{
		heapify(i, a, n);
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

		n += 1;


		int *a = new int[n];
		a[0] = -1;
		for (int i = 1; i < n; i++)
		{
			cin >> a[i];
		}

		out(a, n);


		build_max_heap(a, n);


		out(a, n);







	}
	return 0;
}
