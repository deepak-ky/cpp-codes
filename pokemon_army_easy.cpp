#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back



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
		int n, q;
		cin >> n >> q;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int ans = 0;
		int check = true;
		int i = 0;
		while (i < n)
		{
			if (check)
			{
				if (a[i + 1] < a[i] && i + 1 < n)
				{
					ans += a[i];
					check = false;
				}
			}
			else
			{
				if (a[i + 1] > a[i] && i + 1 < n)
				{
					ans -= a[i];
					check = true;

				}
			}
			i++;
			//cout << ans << endl;
		}
		if (check)
		{
			ans += a[n - 1];
		}
		cout << ans << endl;
	}
	return 0;
}
