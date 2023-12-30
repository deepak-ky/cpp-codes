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
class set_compare
{
public:
	bool operator()(pair<string, int> p1, pair<string, int> p2)
	{
		return p1.second > p2.second;

	}

};
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	pair<string, int> p1 = make_pair("A", 100);
	pair<string, int> p2 = make_pair("B", 95);
	pair<string, int> p3 = make_pair("C", 190);
	pair<string, int> p4 = make_pair("D", 172);
	multiset<pair<string, int> , set_compare> ms;
	ms.insert(p1);
	ms.insert(p2);
	ms.insert(p3);
	ms.insert(p4);
	for (auto p : ms)
	{
		cout << p.first << " - > " << p.second << "\n";
	}



	return 0;
}
