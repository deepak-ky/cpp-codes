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
int findsum(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + a[i];
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
		int n, k;
		cin >> n >> k;
		int a[n];
		int b[n];
		asdf(a, n);
		asdf(b, n);
		sort(a, a + n);
		sort(b, b + n);
		if (k == 0)
		{
			cout << findsum(a, n) << endl;
		}
		else if (a[0] >= b[n - 1])
		{
			cout << findsum(a, n) << endl;
		}
		else
		{

			int i = 0;
			int j = n - 1;
			while ((a[i] <= b[j]) && k > 0)
			{

				int val1 = a[i];
				int val2 = b[j];

				a[i] = val2;
				b[j] = val1;

				i++;
				j--;
				k--;
			}
			cout << findsum(a, n) << endl;
		}


	}
	return 0;
}
