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
bool solutionExists = false;
string solutionPath;

void solveMaze(char **mat, int row, int col, int i, int j, string path)
{
	// if (solutionExists)
	// {
	// 	return;
	// }
	if (i >= row || j >= col)
	{
		return;
	}
	if (mat[i][j] == 'X')
	{
		return;
	}
	if (i == row - 1 && j == col - 1)
	{
		solutionExists = true;
		cout << path << endl;
		solutionPath = path;
		return;
	}
	solveMaze(mat, row, col, i, j + 1, path + "R");
	solveMaze(mat, row, col, i + 1, j, path + "D");
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
		char **mat = new char*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new char[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
			}
		}
		solveMaze(mat, n, m, 0, 0, "");
		if (solutionExists)
		{
			for (int i = 0; i < solutionPath.length(); i++)
			{
				cout << solutionPath[i] << " ";
			}
			cout << endl;
			int solarr[n][m] = {0};
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					solarr[i][j] = 0;
				}

			}
			int k = 0;
			int d = 0;
			solarr[k][d] = 1;
			for (int i = 0; i < solutionPath.length(); i++)
			{
				if (solutionPath[i] == 'D')
				{
					k++;
					solarr[k][d] = 1;
				}
				else
				{
					d++;
					solarr[k][d] = 1;
				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << solarr[i][j] << " ";
				}
				cout << endl;

			}
		}
		else cout << "-1";

	}
	return 0;
}
