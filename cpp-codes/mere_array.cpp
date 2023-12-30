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

int gcd(int a, int b)
{
	if (b % a == 0)
	{
		return a;
	}
	else return gcd(b % a, a);
}

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
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[i] = a[i];
		}
		int m = *min_element(a, a + n);
		bool flag = 1;
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			if ( mp[i] != a[i] && (gcd(mp[i], m) != m || gcd(a[i], m) != m))
			{
				flag = 0;
				break;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}



	return 0;
}
