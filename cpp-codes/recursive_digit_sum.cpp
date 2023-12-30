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

int recursive_digit_sum(int n)
{
	if (n <= 9)
	{
		return n;
	}
	else
	{
		int w = 0;
		while (n > 0)
		{
			int r = n % 10;
			n = n / 10;
			w += r;
		}
		return recursive_digit_sum(w);
	}
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string s;
		int k;
		cin >> s;
		cin >> k;
		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int c = s[i] - '0';
			sum += c;
		}
		sum *= k;
		cout << recursive_digit_sum(sum);

	}
	return 0;
}
