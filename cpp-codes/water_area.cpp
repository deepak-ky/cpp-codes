#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
		int n = sizeof(a) / sizeof(int);
		int left_max[n];
		int right_max[n];
		left_max[0] = a[0];
		int current_max = a[0];
		for (int i = 0; i < n; i++)
		{
			left_max[i] = current_max;
			if (a[i] > current_max)
			{
				current_max = a[i];
			}
		}
		right_max[n - 1] = a[n - 1];
		current_max = a[n - 1];
		int ans = 0;

		for (int i = n - 1 ; i >= 0; i--)
		{
			int w = min(left_max[i], current_max);
			int h = w - a[i];
			if (h > 0) ans += h;
			if (a[i] > current_max)
			{
				current_max = a[i];
			}

		}

		cout << ans << endl;

	}
	return 0;
}


