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

int return_maximum_path_sum(int **mat, int n, int m)
{
	int dp[n][m];

	for (int i = 0; i < m; i++)
	{
		dp[n - 1][i] = mat[n - 1][i];
	}

	int ans = INT_MIN;


	for (int i = (n - 2); i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + mat[i][j];
			}
			else if (j == (m - 1))
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1]) + mat[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i + 1][j], max(dp[i + 1][j + 1], dp[i + 1][j - 1])) + mat[i][j];
			}

			if (i == 0)
			{
				ans = max(ans, dp[i][j]);
			}
		}


	}

	return ans;


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
				cin >> mat[i][j];
			}
		}
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 	{
		// 		cout << mat[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		cout << return_maximum_path_sum(mat, n, m);

	}
	return 0;
}
