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


bool is_safe(int **mat, int i, int j, int n, int m)
{
	//No queen should in same row , same coloumn , left diagonal , right diagonal
	for (int col = 0; col < m; col++)
	{
		if (mat[i][col] == 1)
		{
			return false;
		}
	}

	for (int row = 0; row < n; row++)
	{
		if (mat[row][j] == 1)
		{
			return false;
		}
	}

	//the above two cases consider some redundanat cases
	//no queen can be placed in the same column after i , so we do not need to check after i
	//no queen can be placed in the same row after j , so we do not need to check after j

	//similiarly for both the diagonals we only need to check the
	//upper part of both the diagonals

	int row = i - 1;
	int col = j - 1;

	while (row >= 0 && col >= 0)
	{
		if (mat[row][col] == 1)
		{
			return false;
		}
		else
		{
			row --;
			col--;
		}

	}

	row = i - 1;
	col = j + 1;
	while (row >= 0 && col < n)
	{
		if (mat[row][col] == 1)
		{
			return false;
		}
		else
		{
			row --;
			col++;
		}
	}

	return true;



}

bool place_n_queens(int **mat, int i, int j, int n, int m)
{
	if (i == n)
	{
		//Here I have placed all the queens successfully
		return true;
	}
	if (j == m)
	{
		//I was trying to place the queens in the ith row but no place was suitable
		return false;
	}

	//Can I place a queen at the current position
	if (is_safe(mat, i, j, n, m))
	{
		mat[i][j] = 1;
		bool can_place_rest_of_the_queens = place_n_queens(mat, i + 1, 0, n, m);

		if (can_place_rest_of_the_queens == true)
		{

			return true;


		}
		else
		{
			mat[i][j] = 0;
			return place_n_queens(mat, i, j + 1, n, m);
		}
	}
	else
	{
		return place_n_queens(mat, i, j + 1, n, m);
	}


}

int cnt = 0;

void display_all_solutions(int **mat, int i, int j, int n, int m)
{
	if (i == n)
	{
		cnt++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		return;
	}
	if (j == m)
	{
		return;
	}

	//Can I place a queen at the current position
	if (is_safe(mat, i, j, n, m))
	{
		mat[i][j] = 1;
		display_all_solutions(mat, i + 1, 0, n, m);
		mat[i][j] = 0;
		display_all_solutions(mat, i, j + 1, n, m);
	}
	else
	{
		display_all_solutions(mat, i, j + 1, n, m);
	}

	return;

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
				mat[i][j] = 0;
			}
		}


		//mat[i][j] = 0 indicates no queen has been placed their yet

		/*bool can_place = place_n_queens(mat, 0, 0, n, m);

		if (can_place == false)
		{
			cout << -1 << endl;
		}
		else
		{

			cout << "The queens can be placed : " << endl;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << mat[i][j] << " ";
				}
				cout << endl;
			}



		}*/


		display_all_solutions(mat, 0, 0, n, m);
		cout << cnt << " arrangments possible";

	}
	return 0;
}
