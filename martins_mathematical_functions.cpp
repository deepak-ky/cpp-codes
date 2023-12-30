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
int sum_of_odd_digits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		int r = n % 10;
		if (r % 2 != 0)
		{
			sum += r;
		}
		n = n / 10;
	}
	return sum;
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
		int sum = 0;
		for (int i = 1 ; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{	wer(i);
				if (i == (n / i) )
				{
					sum += sum_of_odd_digits(i);
				}
				else {
					sum += sum_of_odd_digits(i);
					sum += sum_of_odd_digits(n / i);
				}
			}
		}
	}
	cout << endl << sum;
	return 0;
}
