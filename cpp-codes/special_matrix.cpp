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

const int N =  505;
int dp[N][N];

int find_Ways(int **mat, int i, int j, int n, int m)
{
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	if (i >= n || j >= m)
	{
		return dp[i][j] = 0;
	}
	if (mat[i][j] == 0)
	{
		return dp[i][j] = 0;
	}
	if (i == n - 1 && j == m - 1)
	{
		return dp[i][j] = 1;
	}

	int a = find_Ways(mat, i + 1, j, n, m);
	int b = find_Ways(mat, i, j + 1, n, m);

	return dp[i][j] = a + b;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));


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


		cout << find_Ways(mat, 0, 0, n, m);

	}
	return 0;
}
