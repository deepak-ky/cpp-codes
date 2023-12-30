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
		string s;
		cin >> s;
		int odd_number_at_even_indices = 0;
		int odd_number_at_odd_indices = 0;
		int even_number_at_even_indices = 0;
		int even_number_at_odd_indices = 0;
		for (int i = 0; i < n; i++)
		{
			int w = s[i] - '0';
			if ( (i + 1) & 1)
			{
				//odd number index
				if (w & 1)
				{
					odd_number_at_odd_indices++;
				}
				else even_number_at_odd_indices++;

			}
			else
			{
				//even number index
				if (w & 1)
				{
					odd_number_at_even_indices++;
				}
				else even_number_at_even_indices++;
			}
		}

		//Raze -> only degrade odd indices
		//Breach -> only degrade even indices
		int i = 0;
		while ( i < n - 1)
		{
			if (i + 1 & 1) // raze -> chance
			{
				if (even_number_at_odd_indices > 0)
				{
					even_number_at_odd_indices--;
				}
				else if (odd_number_at_odd_indices > 0)
					odd_number_at_odd_indices--;
			}
			else     // breach -> even
			{
				if (odd_number_at_even_indices > 0)
				{
					odd_number_at_even_indices--;
				}
				else if (even_number_at_even_indices > 0)
					even_number_at_even_indices--;
			}
			i++;
		}
		if (even_number_at_even_indices != 0 || even_number_at_odd_indices != 0)
		{
			cout << 2 << endl;
		}
		else cout << 1 << endl;

	}
	return 0;
}
