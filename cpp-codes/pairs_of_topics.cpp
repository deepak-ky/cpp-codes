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

typedef tree < pair<int, int> , null_type , less<pair<int, int > > , rb_tree_tag , tree_order_statistics_node_update > PBDS;


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
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		c[i] = a[i] - b[i];
	}
	int ans = 0;
	PBDS pbds;
	for (int i = 0; i < n; i++)
	{
		ans += pbds.size() - pbds.order_of_key({ -c[i], mod});
		pbds.insert({c[i] , i});
	}
	cout << ans;
	return 0;
}
