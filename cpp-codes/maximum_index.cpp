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
		int a[n];
		asdf(a, n);
		int smallest_from_left[n];
		int biggest_from_right[n];
		smallest_from_left[0] = a[0];
		for (int i = 1; i < n; i++)
		{
			smallest_from_left[i] = min(a[i], smallest_from_left[i - 1]);
		}
		biggest_from_right[n - 1] = a[n - 1];
		for (int i = (n - 2); i >= 0; i--)
		{
			biggest_from_right[i] = max(a[i], biggest_from_right[i + 1]);
		}
		int i = 0;
		int j = 0;
		int max_so_far = 0;
		while (i < n && j < n)
		{
			if (smallest_from_left[i] <= biggest_from_right[j])
			{
				max_so_far = max(max_so_far, j - i);
				j = j + 1;
			}
			else
			{
				i = i + 1;
			}
		}
		cout << max_so_far << endl;
	}
	return 0;
}
