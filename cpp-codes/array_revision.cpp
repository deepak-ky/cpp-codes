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
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int end_index = 0;
		int start_index = 0;
		int sum = 0;
		while (end_index <= (n - 1))
		{
			sum = sum + a[end_index];
			if (sum > k)
			{
				while (sum > k && start_index <= end_index)
				{
					sum = sum - a[start_index];
					start_index++;
				}
			}
			if (sum == k)
				cnt++;
			end_index++;
		}
		if (end_index >= n || start_index >= n)
		{
			cout << -1 << endl;
		}
		else
			cout << start_index + 1 << " " << end_index + 1 << endl;
	}
	return 0;
}
