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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int curr_height = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= curr_height)
		{
			int w = abs(a[i] - curr_height);
			curr_height = a[i];
			sum += w + 1;
		}
		if (i != (n - 1))
		{
			if (a[i + 1] >= a[i])
			{
				sum += 1;
				curr_height = curr_height;
			}
			else if (a[i + 1] < a[i])
			{
				int w = abs(a[i + 1] - curr_height);
				sum += w;
				sum += 1;
				curr_height = a[i + 1];

			}
		}

	}
	cout << sum;

	return 0;
}
