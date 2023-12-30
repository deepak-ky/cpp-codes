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
		int n, m;
		cin >> n >> m;
		int **mat = new int*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
			}
		}
		int **ans = new int*[n];
		for (int i = 0; i < n; i++)
		{
			ans[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == 0)
				{
					ans[i][j] = 0;
				}
				else
				{
					ans[i][j] = INT_MAX - 1;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (ans[i][j] != 0)
				{


					if (i - 1 >= 0)
					{
						ans[i][j] = min(ans[i][j] , ans[i - 1][j] + 1);
					}
					if (i + 1 < n)
					{
						ans[i][j] = min(ans[i][j] , ans[i + 1][j] + 1);
					}
					if (j - 1 >= 0)
					{
						ans[i][j] = min(ans[i][j] , ans[i][j - 1] + 1);
					}
					if (j + 1 < m)
					{
						ans[i][j] = min(ans[i][j] , ans[i][j + 1] + 1);
					}
				}
			}
		}
		for (int i = n - 1; i >= 0 ; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (ans[i][j] != 0)
				{


					if (i - 1 >= 0)
					{
						ans[i][j] = min(ans[i][j] , ans[i - 1][j] + 1);
					}
					if (i + 1 < n)
					{
						ans[i][j] = min(ans[i][j] , ans[i + 1][j] + 1);
					}
					if (j - 1 >= 0)
					{
						ans[i][j] = min(ans[i][j] , ans[i][j - 1] + 1);
					}
					if (j + 1 < m)
					{
						ans[i][j] = min(ans[i][j] , ans[i][j + 1] + 1);
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}




	}
	return 0;
}
