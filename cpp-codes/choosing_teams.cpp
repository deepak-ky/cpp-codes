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
	int n, k;
	cin >> n >> k;
	int a[n];
	asdf(a, n);
	sort(a, a + n);
	int max_number_of_teams = 2;
	int idx = 2;
	int cnt = 0;
	while (idx < n)
	{
		if (a[idx] + k <= 5)
		{
			cnt++;

		}
		else break;
		idx = idx + 3;

	}
	cout << cnt ;
	return 0;
}
