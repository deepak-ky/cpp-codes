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
	string s;
	cin >> s;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < (s.length()); i++)
	{
		if (s[i] == '4')
		{
			cnt1++;
		}
		else if (s[i] == '7')
		{
			cnt2++;
		}
	}
	if (cnt1 == 0 && cnt2 == 0)
	{
		cout << -1;
	}
	else if (cnt1 >= cnt2)
	{
		cout << 4;
	}
	else if (cnt2 > cnt1)
	{
		cout << 7;
	}


	return 0;
}
