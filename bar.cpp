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
	vector<string> v;
	v.push_back("ABSINTH");
	v.push_back("BEER");
	v.push_back("BRANDY");
	v.push_back("CHAMPAGNE");
	v.push_back("GIN");
	v.push_back("SAKE");
	v.push_back("RUM");
	v.push_back("TEQUILA");
	v.push_back("VODKA");
	v.push_back("WHISKEY");
	v.push_back("WINE");
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		if (a[0] >= '0' && a[0] <= '9')
		{
			int t = stoi(a);
			if (t < 18) cnt++;
		}
		else
		{
			auto it = find(v.begin(), v.end(), a);
			{
				if (it != v.end()) cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}