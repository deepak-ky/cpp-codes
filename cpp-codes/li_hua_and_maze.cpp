#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second

//Prints
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "}"; }

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

int solve(int a1,int b1,int n,int m)
{
	int cnt1 = 0;
		if(a1 - 1  >= 1) cnt1++;
		if(b1 - 1  >= 1) cnt1++;
		if(a1 + 1  <= n) cnt1++;
		if(b1 + 1  <= m) cnt1++;
		return cnt1;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		int a1,b1,a2,b2;
		cin >> a1 >> b1 >> a2 >> b2;
		int opt1 = solve(a1,b1,n,m);
		int opt2 = solve(a2,b2,n,m);
		cout << min(opt1,opt2) << endl;
		


	}
	return 0;
}
