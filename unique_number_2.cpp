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
	int n;
	cin >> n;
	int *a = new int[n];
	int array_xor = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		array_xor = array_xor ^ a[i];
	}
	int set_bit_index = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((array_xor >> i) & 1)
		{
			set_bit_index = i;
			break;
		}
	}
	int bit_0 = 0;
	int bit_1 = 0;
	for (int i = 0; i < n; i++)
	{
		if ((a[i] >> set_bit_index) & 1)
		{
			bit_0 = bit_0 ^ a[i];
		}
		else bit_1 = bit_1 ^ a[i];
	}
	cout << min(bit_1, bit_0) << " " << max(bit_0, bit_1);
	return 0;
}
