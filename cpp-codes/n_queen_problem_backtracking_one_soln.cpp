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

bool is_safe(int **mat, int i, int j, int n, int m)
{
	//out of bound if condition


	//no queen in that coloumn
	for (int row = 0; row < n; row++)
	{
		if (mat[row][j] == 1)
		{
			return false;
		}
	}

	//no one on left diagnol
	int row = i - 1;
	int col = j - 1;
	while (row >= 0 &&  col >= 0)
	{
		if (mat[row][col] == 1)
		{
			return false;
		}
		row--;
		col--;
	}

	//no one on right diagnol
	row = i - 1;
	col = j + 1;
	while (row >= 0 && col < m)
	{
		if (mat[row][col] == 1)
		{
			return false;
		}
		row--;
		col++;
	}

	return true;


}
bool n_queen_soln(int **mat, int i, int n, int m)
{
	if (i >= n)
	{
		return true;
	}
	for (int col = 0; col < m; col++)
	{
		if ( is_safe(mat, i, col, n, m))
		{
			mat[i][col] = 1;

			bool aage_theek_hain = n_queen_soln(mat, i + 1, n, m);

			if (aage_theek_hain == true)
			{
				return true;
			}
			else
			{
				mat[i][col] = 0;
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
		int n;
		cin >> n;
		int m = n;
		int **mat = new int*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = 0;
			}
		}

		bool flag = n_queen_soln(mat, 0, n, m);
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
