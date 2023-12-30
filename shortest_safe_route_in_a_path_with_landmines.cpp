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

bool is_safe(int i, int j, int **mat, int n, int m)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return false;
	}
	if (mat[i][j] == 0)
	{
		return false;
	}
	if (mat[i][j] == 2)
	{
		return false;
	}
	if (i + 1 < n)
	{
		if (mat[i + 1][j] == 0)
		{
			return false;
		}
	}

	if (j + 1 < m)
	{
		if (mat[i][j + 1] == 0)
		{
			return false;
		}
	}


	if ( i - 1 >= 0)
	{
		if (mat[i - 1][j] == 0)
		{
			return false;
		}
	}


	if (j - 1 >= 0)
	{
		if (mat[i][j - 1] == 0)
		{
			return false;
		}
	}


	return true;
}


int traverse_in_matrix(int i, int j , int **mat , int n, int m)
{
	//the current location is safe
	if (j == m - 1)
	{
		//ending condition
		return 0;
	}

	mat[i][j] = 2;

	int op1 = INT_MAX;
	int op2 = INT_MAX;
	int op3 = INT_MAX;
	int op4 = INT_MAX;

	if (is_safe(i + 1, j, mat, n, m))
	{
		op1 = traverse_in_matrix(i + 1, j, mat, n, m);
	}

	if (is_safe(i, j + 1, mat, n, m))
	{
		op2 = traverse_in_matrix(i, j + 1, mat, n, m);
	}

	if (is_safe(i - 1, j, mat, n, m))
	{
		op3 = traverse_in_matrix(i - 1, j, mat, n, m);
	}

	if (is_safe(i, j - 1, mat, n, m))
	{
		op4 = traverse_in_matrix(i, j - 1, mat, n, m);
	}


	int op5 = min(op1, op2);
	int op6 = min(op4, op5);

	int ans = 1 + min(op5, op6);

	mat[i][j] = 1;
	return ans;
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

		int ans = INT_MAX;


		for (int i = 0; i < n; i++)
		{
			if (is_safe(i, 0, mat, n, m))
			{
				int w = traverse_in_matrix(i, 0, mat, n, m);
				ans = min(ans, w);
			}
		}

		cout << ans << endl;

	}
	return 0;
}
