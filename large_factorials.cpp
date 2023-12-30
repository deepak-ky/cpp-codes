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

void multiply(vector<int> &v, int x)
{
	int carry = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int w = (v[i] * x + carry);
		v[i] = w % 10;
		carry = w / 10;
	}
	while (carry > 0)
	{
		v.push_back(carry % 10);
		carry = carry / 10;
	}

}
void large_fact(int n)
{
	vector<int> v;
	v.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		multiply(v, i);
	}
	reverse(v.begin(), v.end());
	for (auto x : v) cout << x;
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
	large_fact(n);
	return 0;
}
