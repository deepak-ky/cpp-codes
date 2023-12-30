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
int reverse(int A)
{
	if (A == 0 || (A > 2147483647) ||  (A < -2147483647)) return 0;
	bool flag = true;
	if (A < 0) flag = false;
	A = max(A, -A);
	int ans = 0;
	while (A > 0)
	{
		int r = A % 10;
		ans = ans * 10 + r;
		A = A / 10;
	}
	if (flag)
		return ans;
	else return -ans;
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
	cout << reverse(n);
	return 0;
}
