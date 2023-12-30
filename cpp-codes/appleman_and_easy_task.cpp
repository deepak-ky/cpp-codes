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
	int n;
	cin >> n;
	int m = n;
	char mat[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			int cnt1 = 0;
			if (j !=  (n - 1))
			{
				if (mat[i][j + 1] == 'o')
				{
					cnt1 = 1;
				}
			}
			int cnt2 = 0;
			if (j !=  (0))
			{
				if (mat[i][j - 1] == 'o')
				{
					cnt2 = 1;
				}
			}
			int cnt3 = 0;
			if (i !=  (n - 1))
			{
				if (mat[i + 1][j] == 'o')
				{
					cnt3 = 1;
				}
			}
			int cnt4 = 0;
			if (i != (0))
			{
				if (mat[i - 1][j] == 'o')
				{
					cnt4 = 1;
				}
			}
			if ((cnt1 + cnt2 + cnt3 + cnt4) & 1)
			{
				flag = 1;
				break;
			}

		}
	}
	if (flag)
	{
		cout << "NO";
	}
	else cout << "YES";

	return 0;
}
