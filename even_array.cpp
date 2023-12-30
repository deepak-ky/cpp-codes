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
		int even_not_correct = 0;
		int odd_not_correct = 0;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				if (a[i] % 2 != 0)
				{
					even_not_correct++;
				}
			}
			else if (i % 2 != 0)
			{
				if (a[i] % 2 == 0)
				{
					odd_not_correct++;
				}
			}
		}
		//wer(odd_not_correct);
		//wer(even_not_correct);
		if (odd_not_correct != even_not_correct)
		{
			cout << -1 << endl;
		}
		else cout << even_not_correct << endl;
	}
	return 0;
}
