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
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}

		vector<pair<int, int>> original_indices;
		queue<pair < pair<int, int> , int > > q;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == 1)
				{
					q.push({{i, j}, 0});
					original_indices.push_back({i, j});
				}
			}
		}




		while (!q.empty())
		{
			pair< pair<int, int> , int >  p = q.front();
			q.pop();

			pair<int, int> index_pair = p.first;

			int current_distance = p.second;

			int i = index_pair.first;
			int j = index_pair.second;

			if (i - 1 >= 0)
			{
				//If it is zero we can do nothing
				if (mat[i - 1][j] == 0)
				{
					mat[i - 1][j] = current_distance + 1;
					q.push({{i - 1, j}, current_distance + 1});
				}
			}

			if (j - 1 >= 0)
			{
				if (mat[i][j - 1] == 0)
				{
					mat[i][j - 1] = current_distance + 1;
					q.push({{i, j - 1}, current_distance + 1});
				}
			}


			if (i + 1 < n)
			{
				if (mat[i + 1][j] == 0)
				{
					mat[i + 1][j] = current_distance + 1;
					q.push({{i + 1, j}, current_distance + 1});
				}
			}

			if (j + 1 < m)
			{
				if (mat[i][j + 1] == 0)
				{
					mat[i][j + 1] = current_distance + 1;
					q.push({{i, j + 1}, current_distance + 1});
				}
			}


		}


		for (auto x : original_indices)
		{
			int i = x.first;
			int j = x.second;
			mat[i][j] = 0;
		}


		cout << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}


	}
	return 0;
}
