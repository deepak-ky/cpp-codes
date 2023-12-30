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
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int big = 1e15;
	int min_transform = 1e15;
	int c = 2;
	while (true)
	{
		bool flag1 = true;
		int local_ans = 0;
		int p = 1;
		for (int i = 0; i < n; i++)
		{
			int w = pow(c, i);
			if (w > big)
			{
				flag1 = false;
				break;
			}
			local_ans += abs(w - a[i]);

		}
		if (flag1 == false) break;
		min_transform = min(min_transform, local_ans);
		c++;
	}
	cout << min_transform << endl;

	return 0;
}
