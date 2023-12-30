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
			int k, m;
			int ans = INT_MAX;
			for (int a = 1; a <= sqrt(n); a++)
			{

				if (n % a == 0)
				{
					//wer(a);
					int i = a;
					int w = max(a, n - i);
					int j = n / a;
					int w1 = max(j, n - j);
					ans = min(ans, min(w, w1));
				}
			}
			k = min(ans, n - ans);
			m = max(ans, n - ans);
			cout << k << " " << m << endl;
		}
	}
	return 0;
}
