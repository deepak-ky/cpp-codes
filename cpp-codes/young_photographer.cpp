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
	int n, x;
	cin >> n >> x;
	int a[n], b[n];
	int min_ending_point = 10005;
	int max_starting_point = -1;
	for (int i = 0; i < n; i++)
	{
		int w, y;
		cin >> w >> y;
		a[i] = min(w, y);
		b[i] = max(w, y);
		min_ending_point = min(min_ending_point, b[i]);
		max_starting_point = max(max_starting_point, a[i]);
	}
	if (max_starting_point > min_ending_point)
	{
		cout << -1 << endl;
	}
	else
	{
		if (x >= max_starting_point && x <= min_ending_point)
		{
			cout << 0;
		}
		else if (x < max_starting_point)
		{
			cout << abs(x - max_starting_point);
		}
		else cout << abs(x - min_ending_point);
	}
	return 0;
}
