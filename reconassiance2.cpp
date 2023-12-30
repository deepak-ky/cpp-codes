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
	int min = INT_MAX;
	int idx1 = 0;
	int idx2 = 0;
	for (int i = 0; i < (n); i++)
	{
		if (i != (n - 1))
		{
			int w = abs(a[i] - a[i + 1]);

			if (w < min)
			{
				idx1 = i;
				idx2 = i + 1;
				min  = w;
			}
		}
		else
		{
			//wer(i);
			int w = abs(a[i] - a[0]);
			//wer(w);
			if (w < min)
			{
				//cout << "hwerwe";
				idx1 = i;
				idx2 = 0;
				min = w;
			}
		}
	}
	cout << ++idx1 << " " << ++idx2;

	return 0;
}
