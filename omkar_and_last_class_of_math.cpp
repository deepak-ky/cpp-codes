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
		if (n % 2 == 0)
		{
			cout << n / 2 << " " << n / 2 << endl;
		}
		else
		{
			int ans = n - 1;
			for (int i = 2; (i * i) <= n; i++)
			{
				if (n % i == 0)
				{
					flag = true;
					w = max(w, i);
				}
			}
			if (flag == false)
			{
				cout << 1 << " " << n - 1 << endl;
			}
			else if (flag == true)
			{
				cout << w << " " << n - w << endl;
			}

		}
	}
	return 0;
}
