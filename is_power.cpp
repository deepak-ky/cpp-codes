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
int is_power(int n)
{

	if (n == 1 || n == 0) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		float p = log(n) / log(i);
		if ((floor(p) == ceil(p)) && p > 1)
		{
			return true;
		}
	}
	return false;
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
	// n can be expressed as x ^y where y>1 ans x > 0
	int n;
	cin >> n;
	if (is_power(n))
	{
		cout << "yes";
	}
	else cout << "no";
	return 0;
}
