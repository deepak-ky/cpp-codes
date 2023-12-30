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
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 1)
	{
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		cout << -a[0] << endl;
	}
	else
	{
		cout << "1 " << n;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << -a[i]*n << " ";
			a[i] += -a[i] * n;
		}
		cout << endl;
		cout << "1 " << n - 1;
		cout << endl;
		for (int i = 0; i < n - 1; i++)
		{
			cout << -a[i] << " ";
		}
		cout << endl;
		cout << n << " " << n << endl;
		cout << -a[n - 1];
	}


	return 0;
}
