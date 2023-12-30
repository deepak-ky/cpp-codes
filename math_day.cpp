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

int power(int a, int n)
{
	int ans = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			ans = ans * a;
		}
		n = n >> 1;
		a *= a;
	}
	return ans;
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
	test
	{
		int a, n, p;
		cin >> a >> n >> p;
		int ans = a;
		for (int i = 2; i <= n; i++)
		{
			ans = ans % p;
			ans = power(ans, i);
		}
		cout << ans << endl;
	}
	return 0;
}
