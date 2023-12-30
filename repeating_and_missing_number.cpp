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
	int element_xor = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		element_xor = element_xor ^ a[i];
	}
	int perfect_xor = 0;
	for (int i = 1; i <= n; i++)
	{
		perfect_xor = perfect_xor ^ i;
	}
	int value = element_xor ^ perfect_xor;
	int index_of_set_bit = 0;
	for (int i = 31; i >= 0; i--)
	{
		int k = (value >> i);
		if (k & 1)
		{
			index_of_set_bit = i;
			break;
		}
	}
	//wer(index_of_set_bit) << endl;
	int xor_1 = 0;
	int xor_2 = 0;
	for (int i = 0; i < n; i++)
	{
		int v =  a[i] >> index_of_set_bit;
		if (v & 1)  xor_1 = xor_1 ^ a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int v =  i >> index_of_set_bit;
		if (v & 1)  xor_1 = xor_1 ^ i;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == xor_1)
		{
			cnt++;
		}
	}
	if (cnt == 2)
		cout << (xor_1) << " " << (xor_1 ^ value) << endl;
	else cout << (xor_1 ^ value) << " " << (xor_1) << endl;
	return 0;
}
