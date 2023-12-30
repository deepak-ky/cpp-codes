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

typedef pair<int, pair<int, int>> node;

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


		set<node> s;
		for (int i = 0; i < n; i++)
		{
			int w = mat[i][0];
			s.insert({w, {i, 0}});
		}

		int smallest_range = INT_MAX;
		int starting_point , ending_point;

		while (1)
		{
			node w = *s.begin();
			auto it = s.end();
			it--;
			node w1 = *it;


			int low_point = w.first;
			int high_point = w1.first;

			// wer(low_point);
			// wer(high_point);

			if ((high_point - low_point) < smallest_range)
			{
				smallest_range = high_point - low_point;
				starting_point = low_point;
				ending_point = high_point;
			}

			int row_no = w.second.first;
			int col_no = w.second.second;



			if (col_no == m - 1)
			{
				break;
			}
			else
			{
				s.erase(s.begin());
				s.insert({mat[row_no][col_no + 1] , {row_no, col_no + 1}});
			}


		}


		wer(smallest_range);
		wer(starting_point);
		wer(ending_point);




	}
	return 0;
}
