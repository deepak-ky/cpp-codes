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

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	char mat[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	int total_eaten = 0;
	int total_rows = n;
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < m; j++)
		{
			if (mat[i][j] == 'S')
			{
				flag = 0;
			}
		}
		if (flag)
		{
			total_eaten += m;
			total_rows--;
		}

	}
	for (int i = 0; i < m; i++)
	{
		int flag = 1;
		for (int j = 0; j < n; j++)
		{
			if (mat[j][i] == 'S')
			{
				flag = 0;
			}
		}
		if (flag)
		{
			total_eaten += total_rows;

		}

	}
	cout << total_eaten;


	return 0;
}
