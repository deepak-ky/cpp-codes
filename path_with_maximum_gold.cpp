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

int solve(int **mat, int i, int j, int n, int m)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return 0;
	}
	if (mat[i][j] == 0)
	{
		return 0;
	}
	if (mat[i][j] == -1)
	{
		return 0;
	}
	int w = mat[i][j];
	mat[i][j] = -1;
	int op1 = solve(mat, i + 1, j, n, m);
	int op2 = solve(mat, i - 1, j, n, m);
	int op3 = solve(mat, i, j + 1, n, m);
	int op4 = solve(mat, i, j - 1, n, m);
	mat[i][j] = w;
	int op5 = max(op1, op2);
	int op6 = max(op3, op4);
	return w + max(op5, op6);
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
		int ans = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] != 0)
				{
					int w = solve(mat, i, j, n, m);
					ans = max(ans, w);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
