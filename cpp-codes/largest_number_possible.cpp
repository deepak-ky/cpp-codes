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
	int n, s;
	cin >> n >> s;
	string n1 = to_string(n);
	string s1 = to_string(s);
	if (s > (n * 9) || s == 0 	)
	{
		cout << -1;
	}
	else if (s >= 0 && s <= 9)
	{
		cout << s;
		for (int i = 1; i <= (n - 1); i++)
		{
			cout << "0";
		}
	}
	else
	{
		int r = s % 9;
		int q = s / 9;
		int i = 1;
		for (i = 1; i <= (q); i++)
		{
			cout << "9";
		}
		if (i < (n + 1))
		{
			cout << r;
		}
		i++;
		while (i <= n)
		{
			cout << "0" << endl;
			i++;
		}

	}
	return 0;
}
