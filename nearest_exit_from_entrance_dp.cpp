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


		int dist[n][m];
		memset(dist, -1, sizeof(dist));

		queue<pair<int, int>> q;

		dist[i_start][j_start] = 0;
		q.push({i_start, j_start});

		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};

		int ans = -1;


		while (!q.empty())
		{

			pair<int, int> p = q.front();
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int new_i = p.first + dx[k];
				int new_j = p.second + dy[k];

				if (new_i < n && new_j < m && new_i >= 0 && new_j >= 0 && dist[new_i][new_j] == -1 && mat[new_i][new_j] != '+')
				{
					dist[new_i][new_j] = dist[p.first][p.second] + 1;
					q.push({new_i, new_j});

					if (new_i == 0 || new_j == 0 || new_i == n - 1 || new_j == m - 1)
					{
						ans = dist[new_i][new_j];
						break;
					}
				}
			}

			if (ans != -1)
			{
				break;
			}

		}

		cout << ans << endl;


	}
	return 0;
}
