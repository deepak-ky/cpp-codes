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
		int n;
		cin >> n;
		int m = n;



		int a1 , b1 , a2 , b2;
		cin >> a1 >> b1 >> a2 >> b2;

		int start_i = n - b1;
		int start_j = a1 - 1;



		int dest_i = n - b2;
		int dest_j = a2 - 1;


		int ans = -1;
		if (start_i == dest_i && start_j == dest_j)
		{
			ans = 0;
		}
		else
		{
			queue< pair<int, int> > q;

			int distance[n][m];
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					distance[i][j] = INT_MAX;
				}
			}


			distance[start_i][start_j] = 0;
			//visited[start_i][start_j]  = true;

			q.push({start_i, start_j});


			int x_pos[8] = { -2, -2, 2, 2, -1, 1, -1, 1};
			int y_pos[8] = {  1, -1, -1, 1, 2, 2, -2, -2};

			while (!q.empty())
			{
				pair<int, int> p = q.front();
				q.pop();
				int current_i = p.first;
				int current_j = p.second;


				for (int d = 0; d < 8; d++)
				{
					int new_i = current_i + x_pos[d];
					int new_j = current_j + y_pos[d];


					if (new_i < n && new_j < m && new_i >= 0 && new_j >= 0)
					{

						if (distance[new_i][new_j] == INT_MAX)
						{
							distance[new_i][new_j] = distance[current_i][current_j] + 1;
							q.push({new_i, new_j});
						}

						if (new_i == dest_i && new_j == dest_j)
						{
							ans = distance[new_i][new_j];
							break;

						}
					}



				}
			}
		}






		cout << ans << endl;





	}
	return 0;
}
