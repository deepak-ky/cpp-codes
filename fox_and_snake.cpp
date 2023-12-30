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
			mat[i][j] = '.';
		}
	}
	int row = 0;
	int col  = (m - 1);
	int flag = 0;
	int flag1 = 0;
	while (row < n)
	{

		if (flag == 0 && flag1 == 0)
		{
			for (int i = 0; i < m; i++)
			{
				mat[row][i] = '#';
				flag = 1;
				flag1 = 1;
			}
		}
		else if (flag == 1 && flag1 == 0)
		{
			for (int i = (m - 1); i >= 0; i--)
			{
				mat[row][i] = '#';
				flag = 0;
				flag1 = 1;
			}
		}
		else
		{	/*wer(row);
			wer(col);*/
			//cout << mat[row][col] << endl;
			mat[row][col] = '#';
			//cout << mat[row][col] << endl;
			if (col == 0)
			{
				col = (m - 1);
			}
			else if (col == (m - 1))
			{
				col = 0;
			}
			flag1 = 0;
		}

		row++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}
	return 0;
}
