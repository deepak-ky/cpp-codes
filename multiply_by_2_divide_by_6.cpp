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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
		if (n == 1)
		{
			cout << 0 << endl;
		}
		else if ((n % 6 != 0) && (((n * 2) % 6) != 0))
		{
			cout << -1 << endl;
		}
		else
		{
			int cnt = 0;
			int flag = true;
			while (n != 1)
			{
				if (n % 6 == 0)
				{
					n = n / 6;
					cnt++;
				}
				else if (((n * 2) % 6 == 0))
				{
					n = n * 2;
					cnt++;
				}
				else
				{
					flag = false;
					break;
				}

			}
			if (flag) cout << cnt << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}
