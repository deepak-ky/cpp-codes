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

bool is_subset_sum(int *a, int idx, int n, int num)
{
	if ( idx >= n)
	{
		return false;
	}

	if (a[idx] > num)
	{
		return is_subset_sum(a, idx + 1, n, num);
	}
	else if (a[idx] == num)
	{
		return true;
	}
	else return (is_subset_sum(a, idx + 1, n, num - a[idx]) || is_subset_sum(a, idx + 1, n, num));
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
	int num;
	cin >> num;
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (is_subset_sum(a, 0, n, num))
	{
		cout << "A subset with the given sum is present";
	}
	else cout << "Not present";
	return 0;
}
