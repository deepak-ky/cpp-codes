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

int cnt_paths;

void find_paths(int **a, int** ans, int i, int j, int n, int m)
{

	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return;
	}
	if (a[i][j] == 0)
	{
		return;
	}
	if (ans[i][j] == 1)
	{
		//The current position , is already in solution Path
		return;
	}

	if ( i == n - 1 && j == m - 1)
	{
		cnt_paths++;
		ans[i][j] = 1;
		for (int d = 0; d < n; d++)
		{
			for (int k = 0; k < m; k++)
			{
				cout << ans[d][k] << " ";
			}
			cout << endl;
		}
		ans[i][j] = 0;

		cout << endl << endl;
		return;
	}

	ans[i][j] = 1;

	find_paths(a, ans, i, j + 1, n, m);
	find_paths(a, ans, i, j - 1, n, m);
	find_paths(a, ans, i + 1, j, n, m);
	find_paths(a, ans, i - 1, j, n, m);

	ans[i][j] = 0;
	return;
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

		cnt_paths = 0;

		find_paths(mat, ans, 0, 0, n, m);

		if (cnt_paths == 0)
		{
			cout << "No paths exist";
		}
		else
		{

			cout <<  cnt_paths << " path exist";
		}





	}
	return 0;
}
