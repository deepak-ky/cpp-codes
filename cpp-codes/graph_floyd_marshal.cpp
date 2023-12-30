#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define size 4
void display_matrix(int mat[][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mat[i][j] == INT_MAX)
			{
				cout << "INF ";
			}
			else cout << mat[i][j] << "   ";
		}
		cout << endl;
	}
}
void floyd_marshall(int mat[][size])
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if ( (mat[i][k] + mat[k][j] ) < mat[i][j])
				{
					mat[i][j] = mat[i][k] + mat[k][j];

				}
			}
		}
	}
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int v, e;
	cin >> v >> e;

	int mat[v][size];
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (i == j) mat[i][j] = 0;
			else mat[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		mat[u][v] = w;
		mat[v][u] = w;
	}
	floyd_marshall(mat);
	display_matrix(mat);

	return 0;
}
