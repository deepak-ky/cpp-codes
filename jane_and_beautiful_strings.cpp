#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;


		//n>=5


		ending_with_constant[n + 1];
		ending_with_vowel[n + 1];


		ending_with_constant[0] = -1;
		ending_with_constant[1] = -1;
		ending_with_constant[2] = -1;

		ending_with_constant[3] = (21 * 26) % mod;

		ending_with_constant[4] = (21 * 21) % mod;


		ending_with_vowel[0] = -1;
		ending_with_vowel[1] = -1;
		ending_with_vowel[2] = -1;

		ending_with_vowel[3] = (5 * 21) % mod;

		ending_with_vowel[4] = (5 * 21) % mod;

		-   ----   -
		^  ^

		for (int i = 5; i < n; i++)
		{
			ending_with_constant[i] = ((ending_with_constant[i - 2] % mod) * (26 % mod)) % mod;
			ending_with_vowel[i] = ((ending_with_vowel[i - 2] % mod) * (21 % mod)) % mod;

		}


		int ans = ((ending_with_constant[n] % mod) + (ending_with_vowel[n] % mod)) % mod;
	}
	return 0;
}
