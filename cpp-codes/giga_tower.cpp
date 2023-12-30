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
bool check_lucky(int n)
{
	while (n > 0)
	{
		int r = n % 10;
		if (r == 8) return true;
		n = n / 10;
	}
	return false;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a;
	cin >> a;
	if (a >= 0)
	{
		for (int i = 1; i <= 12; i++)
		{
			if (check_lucky(a + i))
			{
				cout << i;
				break;
			}
		}
	}
	else
	{
		if (a >= (-8))
		{
			cout << 8 - a;
		}
		else
		{
			for (int i = 1; i <= 12; i++)
			{
				if (check_lucky(-(a + i)))
				{

					cout << i;
					break;
				}
			}
		}
	}
	return 0;
}
