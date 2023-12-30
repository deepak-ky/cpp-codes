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
#define INF                           1000000007
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
	cin >> t;
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
				string w;
				cin >> w;
				if (w.compare("INF") == 0)
				{
					mat[i][j] = INF;
				}
				else
				{
					int g = stoi(w);
					if (g == 10000000 )
					{
						mat[i][j] = INF;

					}
					else mat[i][j] = g;
				}
			}
		}
		for (int v = 0; v < n; v++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (mat[i][j] > mat[i][v] + mat[v][j])
					{
						mat[i][j] = mat[i][v] + mat[v][j];
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == INF)
				{
					cout << "INF" << " ";
				}
				else cout << mat[i][j] << " ";
			}
			cout << endl;
		}


	}
	return 0;
}
