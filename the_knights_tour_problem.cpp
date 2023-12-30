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

bool is_safe(int next_i, int next_j, int **mat, int n, int m)
{
	if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m || (mat[next_i][next_j] != -1))
	{
		return false;
	}
	else return true;
}

bool can_traverse_full(int i, int j, int move_no, int **mat, int *xMove, int *yMove, int n, int m)
{
	if (move_no == (n * n) - 1)
	{
		mat[i][j] = move_no;
		return true;
	}

	for (int k = 0; k < n; k++)
	{
		int next_i = i + xMove[k];
		int next_j = j + yMove[k];
		if (is_safe(next_i, next_j, mat, n, m))
		{
			mat[i][j] = move_no;
			bool flag = can_traverse_full(next_i, next_j, move_no + 1, mat, xMove, yMove, n, m);
			if (flag)
			{
				return true;
			}
			else
			{
				mat[i][j] = -1;
			}

		}

	}

	return false;

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n = 8;
		int m = 8;
		int **mat = new int*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = -1;
			}
		}


		int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
		int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };



		bool flag = can_traverse_full(0, 0, 0, mat, xMove, yMove, n, m);

		if (flag == false)
		{
			cout << "No Solution Exists";
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << mat[i][j] << " ";
				}
				cout << endl;
			}
		}

	}
	return 0;
}
