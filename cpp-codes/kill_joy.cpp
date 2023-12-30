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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n , x;
		cin >> n >> x;
		int *a = new int[n];
		bool all_same = true;
		bool one_same = false;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] != x) all_same = false;
			if (a[i] == x) one_same = true;
			sum += (a[i] - x);
		}
		if (all_same)
		{
			cout << 0 << endl;
		}
		else if (one_same || sum == 0)
		{
			cout << 1 << endl;
		}
		else cout << 2 << endl;
	}



	return 0;
}
