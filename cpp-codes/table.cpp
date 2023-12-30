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
	int mat[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	bool flag1 = false;
	int i1 = 0;
	int i2 = n - 1;
	for (int j = 1; j < (m - 1); j++)
	{
		if ((mat[i1][j] == 1) || (mat[i2][j] == 1))
		{
			flag1 = true;
			break;
		}
	}
	bool flag2 = false;
	int j1 = 0;
	int j2 = m - 1;
	for (int i = 1; i < (n - 1); i++)
	{
		if ((mat[i][j1] == 1) || (mat[i][j2] == 1))
		{
			flag2 = true;
			break;
		}
	}
	if (flag1 || flag2)
	{
		cout << 2;
	}
	else cout << 4;

	return 0;
}
