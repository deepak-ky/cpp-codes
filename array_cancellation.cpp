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
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> v;
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				sum1 += a[i];
			}
			else if (a[i] < 0)
			{
				if (sum1 != 0)
				{
					int w;
					w = sum1;
					int w1 = 0;
					sum1 = max(w1, a[i] + sum1);
					a[i] = min(w1, a[i] + w);

				}
				sum2 += a[i];

			}
		}
		cout << sum1 << endl;
	}

	return 0;
}
