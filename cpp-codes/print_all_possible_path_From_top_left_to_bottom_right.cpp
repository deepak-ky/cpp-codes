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

void solve(int i, int j, int** mat, int n, int m, vector<int> curr_path)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return;
	}

	if (mat[i][j] == -1)
	{
		return;
	}

	if ( i == (n - 1) && j == (m - 1))
	{

		for (auto x : curr_path)
		{
			cout << x << " ";
		}
		cout << mat[i][j];
		cout << endl;
		return;
	}

	int w = mat[i][j];
	mat[i][j] = -1;
	curr_path.push_back(w);

	solve(i + 1, j, mat, n, m, curr_path);
	solve(i, j + 1, mat, n, m, curr_path);

	curr_path.pop_back();
	mat[i][j] = w;
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

		vector<int> v;

		solve(0, 0, mat, n, m, v);
	}
	return 0;
}
