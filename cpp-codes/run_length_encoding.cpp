#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s;
		cin >> s;
		int i = 1;
		int cnt = 1;
		char ch = s[0];
		string ans = "";
		while (i < s.length())
		{
			if (s[i] == ch)
			{
				cnt++;
			}
			else
			{
				ans += ch;
				ch = s[i];
				string tmp = to_string(cnt);
				ans += tmp;
				cnt = 1;
			}
			i++;
		}

		ans += ch;
		string tmp = to_string(cnt);
		ans += tmp;

		cout << ans << endl;
	}
	return 0;
}
