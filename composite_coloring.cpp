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
	//need to use the first unused number how to do that
	int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	test
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		set<int> s;
		int ans[n];
		for (int i = 0; i < n; i++)
		{
			ans[i] = -1;
		}
		int cur_col = 1;
		int w = 0;
		for (int j = 0; j < 11; j++)
		{

			bool got = 0;
			for (int i = 0; i < n; i++)
			{
				if (ans[i] != -1)
					continue;
				//if the number is not divisible
				if (a[i] % prime[j] != 0)
					continue;
				//the number is divisible here
				got = 1;
				ans[i] = cur_col;
			}
			if (got == 1)
				cur_col++;
		}
		cout << cur_col - 1 << endl;
		for (auto x : ans)
		{
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
