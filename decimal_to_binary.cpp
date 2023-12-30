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
string binary(int n)
{
	if (n == 0) return "0";
	string ans = "";
	for (int i = 31; i >= 0; i--)
	{
		int k = n >> i;
		if (k & 1) ans += '1';
		else ans += '0';
	}
	//cout << endl << ans.length() << endl;
	int i = 0;
	while (ans[i] != '1')
	{
		i++;
	}
	//cout << i << endl;
	string w = ans.substr(i, ans.length() - i);
	return w;
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
	int n;
	cin >> n;
	cout << binary(n);
	return 0;
}
