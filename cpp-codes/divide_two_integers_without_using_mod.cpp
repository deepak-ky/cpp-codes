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
		int a, b;
		cin >> a >> b;

		int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;

		a = abs(a);
		b = abs(b);

		int quotient = 0;
		int w = 0;

		cout << (1LL << 31) << endl;

		wer(a);
		wer(b);

		for (int i = 31; i >= 0; i--)
		{

			if ((w + (b << i) ) <= a)
			{
				wer(i);
				wer(w);
				w = w + (b << i);
				wer(w);
				quotient = quotient | (1LL << i);
				wer(quotient);
			}
		}

		wer(quotient);
		wer(sign);

		quotient *= sign;

		wer(quotient);
		cout << a - w << endl;
	}
	return 0;
}
