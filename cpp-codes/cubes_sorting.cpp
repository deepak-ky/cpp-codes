#include<iostream>
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl

typedef tree<int, null_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> PBDS;

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		PBDS pbds;
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int max_operation = (n * (n - 1)) / 2;
		max_operation -= 1;
		int inversions = 0;
		pbds.insert(a[0]);
		for (int i = 1; i < n; i++)
		{
			//cout << a[i] << endl;
			pbds.insert(a[i]);
			int w = pbds.size() - pbds.order_of_key(a[i]) - 1;
			//cout << w << endl;
			inversions += w;
		}
		if (inversions <= max_operation)
		{
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}

	return 0;
}
