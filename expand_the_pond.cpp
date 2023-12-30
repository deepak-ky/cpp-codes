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

int get_max_area(int **mat, int i, int j, int n, int m, int cnt)
{
	if (i == n || j == m || i < 0 || j < 0 )
	{
		return 0;
	}
	if (mat[i][j] == 0)
	{
		return 0;
	}
	if (mat[i][j] == cnt)
	{
		return 0;
	}
	mat[i][j] = cnt;
	int op1 = get_max_area(mat, i, j + 1, n, m, cnt);
	int op2 = get_max_area(mat, i, j - 1, n, m, cnt);
	int op3 = get_max_area(mat, i + 1, j, n, m, cnt);
	int op4 = get_max_area(mat, i - 1, j, n, m, cnt);
	return 1 + op1 + op2 + op3 + op4;

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
		int cnt = 2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == 0)
				{
					mat[i][j] = 1;
					int w = get_max_area(mat, i , j, n, m, cnt);
					cnt++;
					ans = max(ans, w);

					mat[i][j] = 0;
				}
			}
		}
		cout << ans << endl;



	}
	return 0;
}
