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

string cal(string ans, int k)
{
	int l = ans.length();
	string a;
	for (int i = 0; i < l; i++)
	{
		bool b1 = false;
		bool b2 = false;
		if ( ((i - k) >= 0) && ans[i - k] == '1')
		{
			b1 = true;
		}
		if ( (i + k) < l && ans[i + k] == '1')
		{
			b2 = true;
		}
		if ((b1 == true) || (b2 == true))
		{
			a += "1";
		}
		else a += "0";
	}
	return a;
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
		string s;
		cin >> s;
		int len = s.length();
		int k;
		cin >> k;
		string ans;
		for (int i = 0; i < len; i++)
		{
			ans += "1";
		}
		for (int i = 0; i < s.length(); i++)
		{
			char ch = s[i];
			if ( (i - k) >= 0)
			{
				ans[i - k] = ch;
			}
			if ((i + k) < s.length())
			{
				ans[i + k] = ch;
			}
		}
		string for_check = cal(ans, k);
		if (for_check == s)
		{
			cout << ans << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
