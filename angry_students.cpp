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
	test
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int max_len = 0;
		int i = 0;
		while (i < n)
		{
			int c = 0;
			int j = i + 1;
			if (s[i] == 'A')
			{
				int c = 0;
				while (s[j] == 'P' && j < n)
				{
					c++;
					j++;
				}
				if (c > max_len)
				{
					max_len = c;
				}
			}
			if ( c == 0)
			{
				i++;
			}
			else

				i += c;
		}
		cout << max_len << endl;
	}
	return 0;
}
