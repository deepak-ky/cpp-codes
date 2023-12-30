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
string next_similar_number(string a)
{
	int len = a.length();
	int i;
	int operate_upon = -1;
	for (i = len - 2; i >= 0; i--)
	{
		if (a[i] < a[i + 1])
		{
			operate_upon = i;
			break;
		}
	}
	if (operate_upon == -1) return "-1";
	string a1 = a.substr(0, operate_upon);
	string a2 = a.substr(operate_upon, len - operate_upon);
	next_permutation(a2.begin(), a2.end());
	return a1 + a2;
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
	string a;
	cin >> a;
	cout << next_similar_number(a);
	return 0;
}
