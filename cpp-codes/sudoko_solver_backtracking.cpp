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

bool is_safe(int mat[][9], int i, int j, int n, int num)
{



	//no value same in row;
	for (int k = 0; k < 9; k++)
	{
		if (mat[i][k] != 0 && mat[i][k] == num)
		{
			return false;
		}
	}

	//no value same in each coloumn
	for (int k = 0; k < 9; k++)
	{
		if (mat[k][j] != 0 && mat[k][j] == num)
		{
			return false;
		}
	}

	int starting_row = (i / 3) * 3;
	int starting_col = (j / 3) * 3;

	for (int k = starting_row; k <= (starting_row + 2); k++)
	{
		for (int l = starting_col; l <= (starting_col + 2); l++)
		{
			if (mat[k][l] != 0 && mat[k][l] == num)
			{
				return false;
			}
		}
	}
	return true;

}

bool solve_suduko(int mat[][9], int i, int j, int n)
{
	if (i == n)
	{
		return true;
	}
	if (j == n)
	{
		return solve_suduko(mat, i + 1, 0, n);
	}
	if (mat[i][j] != 0)
	{
		return solve_suduko(mat, i, j + 1, n);
	}
	else if (mat[i][j] == 0)
	{
		for (int k = 1; k <= 9; k++)
		{
			if ( is_safe(mat, i, j, n, k))
			{
				mat[i][j] = k;
				bool aage_theek_hain = solve_suduko(mat, i, j + 1, n);
				if (aage_theek_hain == true)
				{
					return true;
				}
				else
				{
					mat[i][j] = 0;
				}
			}
		}
		return false;
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
		n = m = 9;
		int mat[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
			{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
			{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
			{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
			{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
			{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
			{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }
		};

		bool flag = solve_suduko(mat, 0, 0, n);
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
