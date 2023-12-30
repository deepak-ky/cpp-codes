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

void flood_fill(int **mat, int n, int m, int i, int j, int orig_color)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return;
	}

	if (mat[i][j] != orig_color)
	{
		return;
	}

	mat[i][j] = -1;

	flood_fill(mat, n, m, i + 1, j, orig_color);
	flood_fill(mat, n, m, i - 1, j, orig_color);
	flood_fill(mat, n, m, i, j + 1, orig_color);
	flood_fill(mat, n, m, i, j - 1, orig_color);


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


		int sr, sc, newColor;

		cin >> sr >> sc >> newColor;

		int orig_color = mat[sr][sc];

		flood_fill(mat, n, m, sr, sc, orig_color);


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == -1)
				{
					mat[i][j] = newColor;
				}
			}
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout <<  mat[i][j] << " ";
			}
			cout << endl;
		}




	}
	return 0;
}
