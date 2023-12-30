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
	int m;
	int n;
	cin >> m >> n;
	int a[m][n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	int col_no = 0;
	while (col_no < n)
	{

		if ((col_no % 2) == 0)
		{
			for (int i = 0; i < m; i++)
			{
				cout << a[i][col_no] << ", ";
			}

			col_no++;
		}
		else
		{
			for (int i = m - 1; i >= 0; i--)
			{
				cout << a[i][col_no] << ", ";
			}

			col_no++;
		}

	}
	cout << "END";
	return 0;
}
