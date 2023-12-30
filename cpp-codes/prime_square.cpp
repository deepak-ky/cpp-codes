#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second


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
	test
	{
		int n;
		cin >> n;
		if (n & 1)
		{
			int a[n][n];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					a[i][j] = 0;
				}
			}
			for (int i = 0; i < n; i++)
			{
				a[i][i] = 1;
				a[i][n - i - 1] = 1;
			}
			a[0][n / 2] = 1;
			a[n / 2][0] = 1;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << a[i][j] << " ";
				}
				cout << endl;
			}

		}
		else
		{
			int a[n][n];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					a[i][j] = 0;
				}
			}
			for (int i = 0; i < n; i++)
			{
				a[i][i] = 1;
				a[i][n - i - 1] = 1;
			}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << a[i][j] << " ";
				}
				cout << endl;
			}


		}
	}
	return 0;
}
