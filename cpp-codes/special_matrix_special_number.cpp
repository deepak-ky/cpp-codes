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

const int N = 50;
int special_numbers[N];

int get_the_closest_value(int a)
{

	for (int i = 1; i < 50; i++)
	{
		if (special_numbers[i] > a && special_numbers[i - 1] < a)
		{

			/*wer(a);
			wer(special_numbers[i]);
			wer(special_numbers[i - 1]);*/
			int m1 = special_numbers[i] - a;
			int m2 = a - special_numbers[i - 1];

			return min(m1, m2);
			break;
		}
	}
}










int min_number_of_moves(int **mat, int n, int m, bool is_special[])
{


	int min_moves[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			min_moves[i][j] = 0;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a = mat[i][j];
			if (is_special[a] == 1)
			{
				min_moves[i][j] = 0;
			}
			else
			{

				min_moves[i][j] = get_the_closest_value(a);
			}

		}
	}


	int ans = INT_MAX;


	for (int i = 0; i < n; i++)
	{
		int row_value = 0;
		for (int j = 0; j < m; j++)
		{
			row_value += min_moves[i][j];
		}

		ans = min(ans, row_value);
	}

	for (int j = 0; j < m; j++)
	{
		int col_value = 0;
		for (int i = 0; i < n; i++)
		{
			col_value += min_moves[i][j];
		}

		ans = min(ans , col_value);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << min_moves[i][j] << " ";
		}
		cout << endl;
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

		bool is_special[1300];

		memset(is_special, 0, sizeof(is_special));

		for (int i = 0; i < 50; i++)
		{
			int a = i + 1;
			int b = i + 2;

			special_numbers[i] = (a * b) / 2;
			is_special[special_numbers[i]] = true;
		}



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






		cout << min_number_of_moves(mat, n, m, is_special);
	}
	return 0;
}
