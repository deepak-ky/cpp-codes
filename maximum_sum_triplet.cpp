#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl

/*set<int> :: iterator*/int get_val(set<int> optimal_from_left, int n)
{
	auto it = optimal_from_left.lower_bound(n);
	if (it == optimal_from_left.begin()) return -1;
	it--;
	return *(it);
}

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
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int max_from_right[n];
	max_from_right[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i] > max_from_right[i + 1])
		{
			max_from_right[i] = a[i];
		}
		else
		{
			max_from_right[i] = max_from_right[i + 1];
		}
	}
	//ut(max_from_right, n);
	set<int> optimal_from_left;
	optimal_from_left.insert(a[0]);
	int ans = INT_MIN;
	for (int i = 1; i < n - 1; i++)
	{
		int v = get_val(optimal_from_left, a[i]);
		if (v == -1) continue;
		int w = v;
		int w2 = max_from_right[i];
		int w1 = w + a[i] + max_from_right[i];
		ans = max(ans , w1);
		optimal_from_left.insert(a[i]);
	}
	cout  << ans << endl;
	return 0;
}
