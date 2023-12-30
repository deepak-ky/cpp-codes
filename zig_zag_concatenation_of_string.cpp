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

void zig_zag_string(string a , int n)
{
	if (n == 1)
	{
		cout << a << endl; return;
	}

	int len = a.length();

	string ans[n];

	int row = 0;
	bool direction_down;

	for (int i = 0; i < len; i++)
	{
		ans[row].push_back(a[i]);

		if (row == 0)
		{
			direction_down = true;
		}

		else if (row == n - 1)
		{
			direction_down = false;
		}

		if (direction_down)
		{
			row++;
		}
		else row--;

	}

	for (auto s : ans)
	{
		cout << s;
	}
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
	string a;
	cin >> a;

	int n;
	cin >> n;

	zig_zag_string(a, n);

	return 0;
}
