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

int max_gold_catch(int n, int m, int **mat)
{
	int dp[n][m];

	for (int j = m - 1; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			if (j == m - 1)
			{
				dp[i][j] = mat[i][j];
			}
			else
			{
				int op1 = INT_MIN;
				int op2 = INT_MIN;
				int op3 = INT_MIN;

				if (i - 1 >= 0)
				{
					op1 = dp[i - 1][j + 1];
				}

				op2 = dp[i][j + 1];

				if (i + 1 < n)
				{
					op3 = dp[i + 1][j + 1];
				}

				int v = max(op1, max(op2, op3));

				dp[i][j] = mat[i][j] + v;
			}
		}
	}


	int ans = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		ans = max(ans  , dp[i][0]);
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


		cout << max_gold_catch(n, m, mat);
	}
	return 0;
}
