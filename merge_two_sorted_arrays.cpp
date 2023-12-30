#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define asdff(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n, n1;
		cin >> n >> n1;
		int a1[n];
		asdf(a1, n);
		int a2[n1];
		asdf(a2, n1);
		int i = 0;
		int j = 0;
		int c = 0;
		int a[n + n1];
		while (i < n && j < n1)
		{
			if (a1[i] <= a2[j])
			{
				a[c] = a1[i];
				i++;
				c++;
			}
			else
			{
				a[c] = a2[j];
				j++;
				c++;
			}
		}
		for (int k = i; k < n; k++)
		{
			a[c] = a1[k];
			c++;
		}
		for (int k = j; k < n1; k++)
		{
			a[c] = a2[k];
			c++;
		}
		//wer(c);
		for (int i = 0; i < c; ++i)
		{
			/* code */cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
