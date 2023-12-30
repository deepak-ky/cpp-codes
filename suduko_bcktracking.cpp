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
int start(int n)
{
	if (n >= 0 && n <= 2)
	{
		return 0;
	}
	if (n >= 3 && n <= 5)
	{
		return 3;
	}
	if (n >= 6 && n <= 8)
	{
		return 6;
	}
}

bool is_safe(int **mat, int i, int j, int n, int m, int num)
{
	//No num should be in the same coloumn
	for (int row = 0; row < n; row++)
	{
		if (mat[row][j] == num)
		{
			return false;
		}
	}


	//No num should in the same row

	for (int col = 0; col < m; col++)
	{
		if (mat[i][col] == num)
		{
			return false;
		}
	}


	//No num should be in the box

	int i_start = start(i);
	int j_start = start(j);

	for (int k = i_start; k <= (i_start + 2); k++)
	{
		for (int d = j_start; d <= (j_start + 2); d++)
		{
			if (mat[k][d] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool can_fill_suduko(int **mat, int i, int j, int n, int m)
{
	if (i == n)
	{
		return true;
	}
	if (j == m)
	{
		return can_fill_suduko(mat, i + 1, 0, n, m);
	}

	if (mat[i][j] != 0)
	{
		return can_fill_suduko(mat, i, j + 1, n, m);
	}

	//for the current position I have 9 options
	for (int num = 1; num <= 9; num++)
	{
		if (is_safe(mat, i, j, n, m, num))
		{
			mat[i][j] = num;
			bool aage_place_kar_sakten_hain = can_fill_suduko(mat, i, j + 1, n, m);
			if (aage_place_kar_sakten_hain == true)
			{
				return true;
			}
			else
			{
				mat[i][j] = 0;
			}
		}
	}


	return false;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n = 9;
		int m = 9;

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



		bool can_fill = can_fill_suduko(mat, 0, 0, n, m);







		if (can_fill)
		{
			cout << "Yes , the suduko can be filled";
			cout << endl << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << mat[i][j] << " ";
				}
				cout << endl;
			}
		}
		else
		{
			cout << "No";
		}

	}
	return 0;
}
