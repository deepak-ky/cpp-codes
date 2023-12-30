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

int ans;

void solve(int i, int j, int dest_i, int dest_j, int **mat, int n, int m, int curr_dist)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return;
	}

	if (i == dest_i && j == dest_j)
	{
		ans = max(ans, curr_dist);
		return;
	}

	if (mat[i][j] == 2)
	{
		return;
	}


	mat[i][j] = 2;
	/*
	    int op1 = INT_MIN;
	    int op2 = INT_MIN;
	    int op3 = INT_MIN;
	    int op4 = INT_MIN;*/

	if (i + 1 < n && mat[i + 1][j] != 0)
	{
		solve(i + 1, j, dest_i, dest_j, mat, n, m, curr_dist + 1);
	}

	if (i - 1 >= 0 && mat[i - 1][j] != 0)
	{
		solve(i - 1, j, dest_i, dest_j, mat, n, m, curr_dist + 1);
	}

	if (j + 1 < m && mat[i][j + 1] != 0)
	{
		solve(i, j + 1, dest_i, dest_j, mat, n, m, curr_dist + 1);
	}

	if (j - 1 >= 0 && mat[i][j - 1] != 0)
	{
		solve(i, j - 1, dest_i, dest_j, mat, n, m, curr_dist + 1);
	}

	mat[i][j] = 1;
	return;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		ans = -1;


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
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

		int src_i;
		int src_j;

		cin >> src_i >> src_j;


		int dest_i;
		int dest_j;

		cin >> dest_i >> dest_j;


		solve(src_i, src_j, dest_i, dest_j, mat, n, m, 0);


		cout << ans << endl;

	}
	return 0;
}
