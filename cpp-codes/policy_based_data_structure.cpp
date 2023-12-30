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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	PBDS pbds;
	pbds.insert(10);
	pbds.insert(1);
	pbds.insert(15);
	pbds.insert(4);
	pbds.insert(3);

	for (int i = 0; i < (pbds.size()); i++)
	{
		cout << i << " -> " << *pbds.find_by_order(i) << endl;
	}


	// The number of elements which are strictly lesser than the given number

	cout << pbds.order_of_key(11);


	return 0;
}
