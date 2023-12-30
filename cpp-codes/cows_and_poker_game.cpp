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
	int len;
	cin >> len;
	string a;
	cin >> a;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'I')
		{
			cnt1++;
		}
		else if (a[i] == 'A')
		{
			cnt2++;
		}
	}
	if (cnt1 >= 2)
	{
		cout << 0;
	}
	else if (cnt1 == 1)
	{
		cout << 1;
	}
	else cout << cnt2;
	return 0;
}
