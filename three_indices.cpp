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
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int a1, b, c;
		a1 = b = c = -1;
		int val;
		val = a[0];
		a1 = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] < val)
			{
				val = a[i];
				a1 = i;
			}
			else break;
		}
		if (a1 == n - 1)
		{
			cout << "NO" << endl;

		}
		else
		{
			//wer(a1);
			int val1 = a[a1];
			b = a1 + 1;
			for (int i = a1 + 1; i < n; i++)
			{
				if (a[i] > val1)
				{
					val1 = a[i];
					b = i;
				}
				else break;
			}
			//wer(b);
			if (b == n - 1)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YES" << endl;
				cout << a1 + 1 << " " << b + 1 << " " << b + 1 + 1 << endl;
			}
		}
	}


	return 0;
}
