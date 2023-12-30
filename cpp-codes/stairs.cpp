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

int solve(int &a)
{
	int pow = 2;
	int p = 1;
	int cnt = 0;
	while (true)
	{
		p = p * pow;
		int w = p - 1;
		int w1 = p;
		int n = (w * w1) / 2;
		if (n > a)
		{
			break;
		}
		if ( n <= a)
		{
			a = a - n;
			cnt++;
		}
	}
	return cnt;
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
	test
	{
		int a;
		cin >> a;
		int cnt = 0;
		cout << solve(a) << endl;
	}

	return 0;
}
