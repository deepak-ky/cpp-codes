#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

int mat[5][15];

//h -> rows

int max_score(int h)
{
	int dp[h][5];
	for (int i = 0; i < 5; i++)
	{
		dp[0][i] = mat[0][i];
	}
	for (int i = 1; i < h; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dp[i][j] = mat[i][j];
			if (j == 0)
			{
				dp[i][j] += max(dp[i - 1][j], dp[i - 1][j + 1]);
			}
			else if (j == 4)
			{
				dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
			else
			{
				dp[i][j] += max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1]));
			}
		}
	}


	return max(dp[h - 1][1] , max(dp[h - 1][2], dp[h - 1][3]));

}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int h;
		cin >> h;
		memset(mat, 0, sizeof(mat));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int w;
				cin >> w;
				mat[i][j] = w;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (mat[i][j] == -1)
				{
					mat[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}


		cout << max_score(h) << endl;
	}
	return 0;
}
