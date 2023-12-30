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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int no_of_days, no_print_days;
		cin >> no_print_days >> no_of_days;
		int ans = 0;
		int cal = 0;
		if (no_of_days >= no_print_days)
		{
			ans += 1;
			cal = no_print_days - 1;
		}
		else if (no_of_days < no_print_days)
		{
			cal = no_of_days;
		}
		ans += ((cal) * (cal + 1)) / 2;
		cout << ans << endl;
	}

	return 0;
}