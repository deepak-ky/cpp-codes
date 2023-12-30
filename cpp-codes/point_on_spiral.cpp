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
	int x1, y1;
	cin >> x1 >> y1;
	int cntr = 0;//cnt of number of left turns it takes
	int x = 0;
	int y = 0;
	int takingjumpof = 1;
	int cnt_jumps;
	//take jumps of 3 two times;

	x = x + 1;
	y = y;


	x = x;
	y = y + 1;

	x = x - 1;
	y = y;

	x = x;
	y = y - 1;


	return 0;
}
