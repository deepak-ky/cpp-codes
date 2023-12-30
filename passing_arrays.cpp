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

const int m = 2;

void pass_array(int *a)
{
	for (int i = 0; i < 2; i++)
	{
		a[i] = a[i] * 2;
		cout << a[i] << " ";
	}
}

void pass_matrix(int mat[][m], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] *= 2;
		}
		//cout << endl;
	}
}

void pass_matrix_dynamically(int **mat, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] *= 3;
		}
		//cout << endl;
	}
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int *a = new int[2] {5, 6};
		pass_array(a);
		out(a, 2);

		cout << endl;
		int n = 2;
		//int m = 2;

		int mat[n][m] = {{9, 8}, {7, 6}};

		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 	{
		// 		cin >> mat[i][j];
		// 	}
		// }

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		//pass_matrix(mat, n, m);
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}



		int row = 2;
		int col = 2;

		int **matrix = new int*[row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				//cin >> matrix[i][j];
				matrix[i][j] = mat[i][j];
			}
		}

		pass_matrix_dynamically(matrix, row, col);
		cout << endl;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout <<  matrix[i][j] << " ";
			}
			cout << endl;
		}







	}
	return 0;
}
