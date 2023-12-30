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
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
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
		//Naive Approach
		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				if (mat[i][j] == 1)
				{

					for (int k = 0; k < m; k++)
					{
						if (mat[i][k] == 0)
						{
							mat[i][k] = 2;
						}
					}
					for (int k = 0; k < n; k++)
					{
						if (mat[k][j] == 0)
						{
							mat[k][j] = 2;
						}
					}
					break;

				}
			}
		} for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == 2)
				{
					mat[i][j] = 1;
				}

			}
		}*/

		bool row_present = false;
		bool col_present = false;

		//m ->rows //n->cols

		for (int i = 0; i < m; i++)
		{
			if (mat[0][i] == 1)
			{
				row_present = true;
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (mat[i][0] == 1)
			{
				col_present = true;
				break;
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (mat[i][j] == 1)
				{
					mat[i][0] = 1;
					mat[0][j] = 1;
				}
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (mat[i][0] == 1 || mat[0][j] == 1)
				{
					mat[i][j] = 1;
				}
			}
		}
		if (row_present)
		{
			for (int i = 0; i < m; i++)
			{
				mat[0][i] = 1;
			}
		}
		if (col_present)
		{
			for (int i = 0; i < n; i++)
			{
				mat[i][0] = 1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
