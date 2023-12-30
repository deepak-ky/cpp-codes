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

int find_max_contigous_sum(int *a, int n)
{
	int dp[n];
	dp[0] = a[0];
	int ans = a[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + a[i] , a[i]);
		ans = max(ans, dp[i]);
	}

	return ans;
}


int maximum_sum_rectangle(int **mat, int n, int m)
{
	int row_sum[n];

	for (int i = 0; i < n; i++)
	{
		row_sum[i] = 0;
	}


	int ans = INT_MIN;


	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				row_sum[k] += mat[k][j];
			}

			ans = max(ans, find_max_contigous_sum(row_sum, n));

		}

		for (int k = 0; k < n; k++)
		{
			row_sum[k] = 0;
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
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl << maximum_sum_rectangle(mat, n, m);





	}
	return 0;
}
