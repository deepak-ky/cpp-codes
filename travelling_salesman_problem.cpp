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

const int N = 10;
const int val = (1 << N) - 1;
int dp[val + 1][N + 1];

int travelling_salesman_problem(int current_Status, int pos, int** mat, int n)
{
	//If I have visited all the vertices
	if (current_Status == ((1 << n) - 1))
	{
		return mat[pos][0];
	}

	if (dp[current_Status][pos] != -1)
	{
		return dp[current_Status][pos];
	}

	int ans = INT_MAX;
	for (int city_no = 0; city_no < n; city_no++)
	{
		//If the city is not previously visited
		if ((current_Status & (1 << city_no)) == 0)
		{
			ans = min(ans, mat[pos][city_no] + travelling_salesman_problem((current_Status | (1 << city_no)), city_no, mat, n));
		}
	}


	return dp[current_Status][pos] = ans;
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
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

		memset(dp, -1, sizeof(dp));



		cout << travelling_salesman_problem(1, 0, mat, n);
	}
	return 0;
}
