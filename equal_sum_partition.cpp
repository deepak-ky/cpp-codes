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

bool fesq(int *a, int idx, int n, int target)
{
	if (a[idx] == target) return true;
	if (idx >= n) return false;
	if (a[idx] > target) return fesq(a, idx + 1, n, target);
	else return fesq(a, idx + 1, n, target - a[idx]) || fesq(a, idx + 1, n, target);
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
	int sum_needed = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum_needed += a[i];
	}
	if (sum_needed & 1) cout << "No";
	else
	{
		if (fesq(a, 0, n, sum_needed / 2))
		{
			cout << "Yes";
		}
		else cout << "No";
	}
	return 0;
}
