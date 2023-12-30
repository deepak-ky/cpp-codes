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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
		int repeating_element = -1;
		int a[n];
		asdf(a, n);
		int element_xor = 0;
		for (int i = 0; i < n; i++)
		{
			element_xor = element_xor ^ a[i];
		}
		for (int i = 0; i < n; i++)
		{
			int w = abs(a[i]);
			if (a[w - 1] < 0)
			{
				repeating_element = w;
				break;
			}
			else
			{
				a[w - 1] = -a[w - 1];
			}
		}
		int perfect_xor = 0;
		for (int i = 1; i <= n; i++)
		{
			perfect_xor = perfect_xor ^ i;
		}
		int w = perfect_xor ^ element_xor;

		cout << repeating_element << " " << ( w ^ repeating_element) << endl;
	}
	return 0;
}
