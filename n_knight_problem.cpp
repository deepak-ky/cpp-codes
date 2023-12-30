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

int cnt = 0;
bool is_safe(int **mat, int i, int j, int n, int m)
{
	if ((j + 1) < m)
	{
		if ((i + 2) < n)
		{
			if (mat[i + 2][j + 1] == 1) return false;
		}
		if ((i - 2) >= 0)
		{
			if (mat[i - 2][j + 1] == 1) return false;

		}
	}
	if ((j + 2) < m)
	{
		if ((i + 1) < n)
		{
			if (mat[i + 1][j + 2] == 1) return false;
		}
		if ((i - 1) >= 0)
		{
			if (mat[i - 1][j + 2] == 1) return false;
		}
	}
	if ((j - 1) >= 0)
	{
		if ((i + 2) < n)
		{
			if (mat[i + 2][j - 1] == 1) return false;
		}
		if ((i - 2) >= 0)
		{
			if (mat[i - 2][j - 1] == 1) return false;

		}
	}
	if ((j - 2) >= 0)
	{
		if ((i + 1) < n)
		{
			if (mat[i + 1][j - 2] == 1) return false;
		}
		if ((i - 1) >= 0)
		{
			if (mat[i - 1][j - 2] == 1) return false;
		}
	}

	return true;

}


bool n_knight_soln(int **mat, int i, int j, int n, int m, int k)
{
	//base case
	// if i have placed all the knights
	if (k == 0)
	{

		for (int i = 0; i < n; i++)
		{
			cout << "{";
			int j = 0;
			for (j = 0; j < m - 1; j++)
			{
				cout << mat[i][j] << "-";
			}
			cout << mat[i][j];
			cout << "} ";
		}
		cout << " ";
		cnt++;
		return true;
	}
	if (i == n)
	{
		return false;
	}
	if (j == m)
	{
		return n_knight_soln(mat, i + 1, 0, n, m, k);
	}


	//rec case
	if ( is_safe ( mat , i , j , n , m))
	{
		mat[i][j] = 1;
		bool aage_theek_hain = n_knight_soln(mat, i, j + 1, n, m, k - 1);
		// if (aage_theek_hain == true)
		// {
		// 	return true;
		// }
		//else
		{
			mat[i][j] = 0;
		}
	}


	return n_knight_soln(mat, i, j + 1, n, m, k);


}
int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n;
		m = n;
		int **mat = new int*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = 0;
			}
		}
		//k is the number of knights to be placed
		int k = n;
		bool val = n_knight_soln(mat, 0, 0, n, m, k);
		cout << endl << cnt << endl;

	}
	return 0;
}
