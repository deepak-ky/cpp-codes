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

bool solve(int **a , int **ans, int i, int j, int n, int m)
{
	if (i >= n || j >= m)
	{
		return false;
	}
	if (a[i][j] == 0)
	{
		return false;
	}

	if (i == (n - 1) && j == (m - 1))
	{
		return true;
	}

	//The current position is safe

	ans[i][j] = 1;

	bool flag1 = solve(a, ans, i + 1, j, n, m);

	if (flag1 == true)
	{
		return true;
	}
	else
	{
		bool flag2 = solve(a, ans, i, j + 1, n, m);
		if (flag2 == true)
		{
			return true;
		}
		else
		{
			ans[i][j] = 0;
			return false;
		}
	}

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
				ans[i][j] = 0;
			}
		}


		bool flag = solve(mat, ans, 0, 0, n, m);

		if (flag)
		{
			cout << "Solution Exists";

			cout << endl;


			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << ans[i][j] << " ";
				}
				cout << endl;
			}
		}

		else
		{
			cout << "Solution does not exist";
		}

	}
	return 0;
}
