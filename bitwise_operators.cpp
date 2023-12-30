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

int get_bit(int n , int pos)
{
	int mask = (1 << pos);
	n = n & mask;
	if ( n > 0) return 1;
	else return 0;
}
int set_bit(int n, int pos)
{
	int mask = (1 << pos);
	n = n | mask;
	return n;
}
int clear_bit(int n , int pos)
{
	int mask = (1 << pos);
	mask = ~mask;
	n = n & mask;
	return n;
}
int update_bit(int n, int pos , int to_bit)
{
	int mask = (1 << pos); mask = ~mask; n = n & mask;
	int mask1 = (to_bit << pos); n = n | mask1;
	return n;
}
int clear_last_i_bits(int n, int i)
{
	int val = ~0;
	int mask = (val << (i + 1));
	n = n & mask;
	return n;
}
int clear_bit_in_range(int n, int i, int j)
{
	int val = ~0;
	int mask1 = (val << (j + 1));
	int mask2 = pow(2, i) - 1;
	int mask = mask1 | mask2;
	n = n & mask;
	return n;
}
int cnt_set_bits_brute_force(int n)
{
	int ans = 0;
	while (n > 0)
	{
		if (n & 1) ans += 1;
		n = n >> 1;
	}
	return ans;
}
int cnt_set_bits_optimized(int n)
{
	int ans  = 0;
	while (n > 0)
	{
		n = n & (n - 1);
		ans++;
	}
	return ans;
}
int decimal_to_binary(int n)
{
	int rep = 0;
	int p = 1;
	int ans = 0;
	while (n > 0)
	{
		int bit = (n & 1);
		bit = bit * p;
		ans += bit;
		p = p * 10;
		n = n >> 1;
	}
	return ans;
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n = 8;
	int i = 1;
	cout << get_bit(n, i);
	cout << endl;
	cout << set_bit(n, i);
	cout << endl;
	cout << clear_bit(n, i);
	cout << endl;
	int to_bit = 1;
	cout << update_bit(n, i, to_bit);
	cout << endl;
	cout << clear_last_i_bits(n, i);
	cout << endl;
	int j = 2;
	cout << clear_bit_in_range(n, i, j);
	cout << endl;
	cout << "1.Set Bits : " << cnt_set_bits_brute_force(n);
	cout << endl;
	cout << "2.Set Bits : " << cnt_set_bits_optimized(n);
	cout << endl;
	cout << "3.Set Bits : " << __builtin_popcount(n);
	cout << endl;
	cout << "Binary Rep of " << n << " is : " << decimal_to_binary(n);

	return 0;
}
