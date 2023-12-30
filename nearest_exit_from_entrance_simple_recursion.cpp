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

bool exit_exists;
int  min_length;


void find_nearest_exit(char **mat, int i, int j, int n, int m, int current_steps)
{
	if (i >= n || j >= m || i < 0 || j < 0) return;
	if (mat[i][j] == '+') return;
	if (mat[i][j] == 'v') return;

	if (mat[i][j] != 'o')
	{
		if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
		{
			wer(i);
			wer(j);
			cout << "here";
			exit_exists = true;
			min_length = min(min_length, current_steps);
			wer(min_length);
			return;
		}
	}

	mat[i][j] = 'v';
	find_nearest_exit(mat, i + 1, j, n, m, current_steps + 1);
	find_nearest_exit(mat, i - 1, j, n, m, current_steps + 1);
	find_nearest_exit(mat, i, j + 1, n, m, current_steps + 1);
	find_nearest_exit(mat, i, j - 1, n, m, current_steps + 1);
	mat[i][j] = '.';
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

		char **mat = new char*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new char[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
			}
		}


		int i_start, j_start;
		cin >> i_start >> j_start;

		exit_exists = false;
		min_length = INT_MAX;


		mat[i_start][j_start] = 'o';


		find_nearest_exit(mat, i_start, j_start, n, m, 0);



		if (exit_exists == true)
		{
			cout << min_length;
		}
		else cout << -1;

	}
	return 0;
}
