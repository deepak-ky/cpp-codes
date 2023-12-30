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
	string w = "0";
	vector<string> with_zero;
	vector<string> without_zero;
	int cnt = 0;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			string a;
			cin >> a;
			int pos = a.find(w);
			if (pos == string::npos)
			{
				without_zero.push_back(a);
			}
			else with_zero.push_back(a);
		}
		if (with_zero.size() == 0)
		{
			cout << 0;
		}
		else
		{
			if (without_zero.size() != 0) cnt += 1;
			cnt += with_zero.size();
			cout << cnt << endl;
			for (auto x : with_zero)
			{
				cout << x << " ";
			}
			if (without_zero.size() != 0)
			{
				cout << without_zero[0];
			}
		}
	}


	return 0;
}
