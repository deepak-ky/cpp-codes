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
int card[100000005];
void definecard(int card[])
{
	card[0] = 0;
	for (int i = 1; i < 100000005; i++)
	{
		card[i] = 2 * i + (i - 1) + card[i - 1];
	}
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	definecard(card);
	test
	{
		int n;
		cin >> n;

		int cnt = 0;
		int getj;
		while (n >= 2)
		{
			for (int i = 0; i < 100; i++)
			{
				if (card[i] == n)
				{
					getj = i;
					break;
				}
				else if (card[i] > n)
				{
					getj = i - 1;
					break;
				}
			}
			if (getj != 0)
			{
				cnt++;
			}

			n = n - card[getj];
		}
		cout << cnt << endl;
	}
	return 0;
}
