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
bool issorted(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1])
			return false;
	}
	return true;
}
int32_t main()
{

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
		if (n == 1 || (issorted(a, n)))
		{
			cout << 1 << endl;
		}
		else
		{
			int min_count = INT_MIN;
			int tocheck = (n / 2) - 1;
			int jumpingfactor = 1;
			for (int i = 0; i <= (tocheck); i++)
			{
				int firstindex = 0;
				int jumpingto = jumpingfactor;
				int cnt = 0;
				if (a[jumpingto] > a[firstindex])
				{
					cnt++;

				}
				firstindex = jumpingto;
				jumpingto = (jumpingto + 1) * 2 - 1;
				int multiplier = 3;
				while (jumpingto < n)
				{
					if (a[jumpingto] > a[firstindex])
					{
						cnt++;
						firstindex = jumpingto;
						jumpingto = (jumpingto + 1) * 2 - 1;
						multiplier = 3;
					}
					else
					{
						jumpingto = (firstindex + 1) * (multiplier) - 1;
						multiplier++;
					}

				}
				min_count = max(min_count, cnt);
				jumpingfactor++;
			}




			cout << min_count + 1 << endl;
		}
	}
	return 0;
}
