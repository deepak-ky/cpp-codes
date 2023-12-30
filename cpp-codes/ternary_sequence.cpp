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
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1;
		cin >> x2 >> y2 >> z2;
		int min1 = min(z1, y2);
		int ans = 0;
		ans += min1 * 2;
		z1 = z1 - min1;
		y2 = y2 - min1;
		int x = x1 + z1;
		int min2 = min(x, z2);
		z2 = z2 - min2;
		int min3 = min(z2, y1);
		ans += min3 * (-2);
		cout << ans << endl;
	}

	return 0;
}
