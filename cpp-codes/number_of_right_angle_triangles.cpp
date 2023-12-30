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

class point
{
public:
	int x;
	int y;
};


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
	point p[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	unordered_map<int, int> hx;
	unordered_map<int, int> hy;
	for (int i = 0; i < n; i++)
	{
		hx[p[i].x]++;
		hy[p[i].y]++;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		point po = p[i];
		sum += (hx[po.x] - 1) * (hy[po.y] - 1);
	}
	cout << sum << endl;
	return 0;
}