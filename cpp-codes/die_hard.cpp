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
		int h, a;
		cin >> h >> a;


		int moves = 0;


		while (1)
		{
			if (moves % 2 == 0)
			{
				h = h + 3;
				a = a + 2;
			}
			else
			{
				if (a > 10)
				{
					h = h - 5;
					a = a - 10;

				}
				else
				{
					h = h - 20;
					a = a + 5;
				}
			}
			if (h > 0 && a > 0)
			{
				moves++;
			}
			else break;

		}


		cout << moves << endl;
	}
	return 0;
}
