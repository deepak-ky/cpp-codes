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
class choclate
{
public:
	int sweetness;
	int bitterness;
	string name;
};
bool compare(choclate c1 , choclate c2)
{
	if (c1.sweetness != c2.sweetness)
	{
		if (c1.sweetness > c2.sweetness)
		{
			return true;
		}
		else return false;
	}
	else if (c1.sweetness == c2.sweetness && c1.bitterness != c2.bitterness)
	{
		if (c1.bitterness < c2.bitterness)
		{
			return true;
		}
		else return false;
	}
	else
	{
		if (c1.name < c2.name)
		{
			return true;
		}
		else return false;
	}
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
	choclate c[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> c[i].sweetness;
	}
	for (int i = 0; i < 6; i++)
	{
		cin >> c[i].bitterness;
	}
	for (int i = 0; i < 6; i++)
	{
		cin >> c[i].name;
	}
	sort(c, c + 6, compare);
	map<int, string> mp;
	for (int i = 0; i < 6; i++)
	{
		mp[i + 1] = c[i].name;
	}
	for (int i = 0; i < 6; i++)
	{
		int w;
		cin >> w;
		cout << mp[w] << " ";
	}
	return 0;
}
