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
	//dp[i] represents number of strings with length i and having no consecutive ones
	int *z_end = new int[n + 1];
	int *o_end = new int[n + 1];
	z_end[0] = o_end[0] = 0;
	z_end[1] = o_end[1] = 1;
	for (int i = 2; i < (n + 1); i++)
	{
		z_end[i] = (z_end[i - 1] % mod + o_end[i - 1] % mod) % mod;
		o_end[i] = z_end[i - 1] % mod;
	}

	cout << (z_end[n] + o_end[n]) % mod << endl;
	return 0;
}
