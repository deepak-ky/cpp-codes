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

bool travel_in_matrix(char **mat, int i, int j, int n, int idx, string s, int len)
{

	if (idx == len)
	{
		return true;
	}

	//base case
	if (i < 0 || j < 0 || i == n || j == n)
	{
		return false;
	}

	if (mat[i][j] != s[idx])
	{
		return false;
	}
	else
	{
		char ch = mat[i][j];
		mat[i][j] = '1';
		bool op1 = travel_in_matrix(mat, i, j + 1, n, idx + 1, s, len);
		bool op2 = travel_in_matrix(mat, i, j - 1, n, idx + 1, s, len);
		bool op3 = travel_in_matrix(mat, i + 1, j, n, idx + 1, s, len);
		bool op4 = travel_in_matrix(mat, i - 1, j, n, idx + 1, s, len);
		bool op5 = travel_in_matrix(mat, i + 1, j + 1, n, idx + 1, s, len);
		bool op6 = travel_in_matrix(mat, i - 1, j + 1, n, idx + 1, s, len);
		bool op7 = travel_in_matrix(mat, i + 1, j - 1, n, idx + 1, s, len);
		bool op8 = travel_in_matrix(mat, i - 1, j - 1, n, idx + 1, s, len);
		if (op1 || op2 || op3 || op4 || op5 || op6 || op7 || op8)
		{
			return true;
		}
		else
		{
			mat[i][j] = ch;
			return false;
		}
	}






}

bool present_in_matrix(char **mat_d, char ** mat , int n, string s)
{
	char ch = s[0];
	int len = s.length();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == ch)
			{
				bool flag = travel_in_matrix(mat_d, i, j, n, 0, s, len);
				if (flag)
				{
					return true;
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < n; j++)
						{
							mat_d[i][j] = mat[i][j];
						}
					}
				}
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
		int l;
		cin >> l;
		vector<string> v(l);
		for (int i = 0; i < l; i++)
		{
			string w;
			cin >> w;
			v[i] = w;
		}



		int n;
		cin >> n;
		int m = n;

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





		char **mat_d = new char*[n];
		for (int i = 0; i < n; i++)
		{
			mat_d[i] = new char[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mat_d[i][j] = mat[i][j];
			}
		}


		for (int i = 0; i < l; i++)
		{

			if (present_in_matrix(mat_d, mat, n, v[i]))
			{
				cout << v[i] << " ";
			}



			// for (int i = 0; i < n; i++)
			// {
			// 	for (int j = 0; j < n; j++)
			// 	{
			// 		cout << mat_d[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					mat_d[i][j] = mat[i][j];
				}
			}



		}



	}
	return 0;
}
