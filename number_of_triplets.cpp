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

typedef tree<int, null_type , less<int>, rb_tree_tag , tree_order_statistics_node_update> PBDS;


int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	PBDS pbds_from_left;
	PBDS pbds_from_right;
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	pbds_from_left.insert(a[0]);
	int smaller_left[n];
	smaller_left[0] = 0;
	for (int i = 1; i < n; i++)
	{
		wer(i);
		cout << endl;
		pbds_from_left.insert(a[i]);
		for (auto x : pbds_from_left)
		{
			cout << x << " ";
		}
		cout << endl;
		int w = pbds_from_left.order_of_key(a[i]);
		cout << "Number of elements smaller than " << a[i] << " : " << w << endl;
		smaller_left[i] = w;
		cout << endl;

	}

	out(smaller_left , n);
	pbds_from_right.insert(a[n - 1]);
	int bigger_right[n];
	bigger_right[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		wer(a[i]);
		cout << endl;
		pbds_from_right.insert(a[i]);
		for (auto x : pbds_from_right)
		{
			cout << x << " ";
		}
		cout << endl;
		int w = pbds_from_right.order_of_key(a[i]);
		cout << "Number of elements bigger than " << a[i] << " : " << pbds_from_right.size() - w - 1 << endl;
		bigger_right[i] = pbds_from_right.size() - w - 1;
		cout << endl;

	}

	out(bigger_right , n);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += (smaller_left[i] * bigger_right[i]);
	}

	cout << ans << endl;



	return 0;
}
