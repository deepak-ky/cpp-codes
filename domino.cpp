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
	int n;
	cin >> n;
	int x[n];
	int y[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	int sum, sum1;
	sum = sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		sum += x[i];
		sum1 += y[i];
	}
	if ((sum % 2 == 0) && (sum1 % 2 == 0))
	{
		cout << 0;
	}
	else if (((sum % 2 == 0) && (sum1 % 2 != 0)) ||  ((sum % 2 != 0) && (sum1 % 2 == 0)))
	{
		cout << -1;
	}
	else if ((sum % 2 != 0) && (sum1 % 2 != 0))
	{
		/*cout << "here";
		wer(sum);
		wer(sum1);*/
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (((x[i] % 2 != 0) && (y[i] % 2 == 0)) || ((x[i] % 2 == 0) && (y[i] % 2 != 0)))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << 1;
		}
		else cout << -1;
	}
	return 0;
}
