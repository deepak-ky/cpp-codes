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

bool  pacific(int i, int j, int n, int m, int **can_reach_pacific, int **mat, int prev_value)
{
	//cout << "i : " << i << "    " << "j: " << j << endl;
	if (i == n || j == m)
	{

		//cout << "1h";
		//cout << endl;
		return false;
	}
	if (mat[i][j] > prev_value)
	{
		//cout << "2h";
		//cout << endl;

		return false;
	}
	if (mat[i][j]  == -1)
	{
		//cout << "3h";
		//cout << endl;

		return false;
	}
	if (can_reach_pacific[i][j] == 1)
	{
		//cout << "4h";
		//cout << endl;

		return true;
	}
	//cout << "5h";

	//cout << endl;
	int w = mat[i][j];
	mat[i][j] = -1;
	bool b1 = pacific(i + 1, j, n, m, can_reach_pacific, mat, w);
	bool b2 = pacific(i - 1, j, n, m, can_reach_pacific, mat, w);
	bool b3 = pacific(i, j + 1, n, m, can_reach_pacific, mat, w);
	bool b4 = pacific(i, j - 1, n, m, can_reach_pacific, mat, w);
	mat[i][j] = w;
	if (b1 || b2 || b3 || b4)
	{
		//cout << "Setting value 1 and returning true" << endl;
		can_reach_pacific[i][j] = 1;
		return true;
	}
	else
	{
		//cout << "NO help obtained";
		return false;
	}

}

bool  atlantic(int i, int j, int n, int m, int **can_reach_atlantic, int **mat, int prev_value)
{
	//cout << "i : " << i << "    " << "j: " << j << endl;
	if (i < 0 || j < 0)
	{

		//cout << "1h";
		//cout << endl;
		return false;
	}
	if (mat[i][j] > prev_value)
	{
		//cout << "2h";
		//cout << endl;

		return false;
	}
	if (mat[i][j]  == -1)
	{
		//cout << "3h";
		//cout << endl;

		return false;
	}
	if (can_reach_atlantic[i][j] == 1)
	{
		//cout << "4h";
		//cout << endl;

		return true;
	}
	//cout << "5h";

	//cout << endl;
	int w = mat[i][j];
	mat[i][j] = -1;
	bool b1 = atlantic(i + 1, j, n, m, can_reach_atlantic, mat, w);
	bool b2 = atlantic(i - 1, j, n, m, can_reach_atlantic, mat, w);
	bool b3 = atlantic(i, j + 1, n, m, can_reach_atlantic, mat, w);
	bool b4 = atlantic(i, j - 1, n, m, can_reach_atlantic, mat, w);
	mat[i][j] = w;
	if (b1 || b2 || b3 || b4)
	{
		//cout << "Setting value 1 and returning true" << endl;
		can_reach_atlantic[i][j] = 1;
		return true;
	}
	else
	{
		//cout << "NO help obtained";
		return false;
	}

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


		//First I am going to do only for pacific
		int **can_reach_pacific = new int*[n];
		for (int i = 0; i < n; i++)
		{
			can_reach_pacific[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				can_reach_pacific[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			can_reach_pacific[i][0] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			can_reach_pacific[0][i] = 1;
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				bool flag = pacific(i, j, n, m, can_reach_pacific, mat, mat[i][j]);
			}
		}



		int **can_reach_atlantic = new int*[n];
		for (int i = 0; i < n; i++)
		{
			can_reach_atlantic[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				can_reach_atlantic[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			can_reach_atlantic[i][m - 1] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			can_reach_atlantic[n - 1][i] = 1;
		}
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m - 1; j++)
			{
				bool flag = atlantic(i, j, n, m, can_reach_atlantic, mat, mat[i][j]);
			}
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				if (can_reach_atlantic[i][j] == 1 && can_reach_pacific[i][j] == 1)
				{
					cout << i << " " << j << endl;
				}
			}
		}


	}
	return 0;
}
