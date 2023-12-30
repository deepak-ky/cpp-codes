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

int find_celebrity(int **a, int n, int m)
{
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		s.push(i);
	}

	while (s.size() != 1)
	{
		int p1 = s.top();
		s.pop();
		int p2 = s.top();
		s.pop();

		if (a[p1][p2] == 1)
		{
			//This means p1 knows p2 , then p1 cannot be a celebrity
			s.push(p2);
		}
		else if (a[p1][p2] == 0)
		{
			//This means p1 does not know p2 , then p2 cannot be a celebrity
			s.push(p1);
		}

	}

	int potential_celebrity = s.top();
	bool celebrity_knows_someone = false;
	for (int i = 0; i < n; i++)
	{
		if (a[potential_celebrity][i] == 1)
		{
			celebrity_knows_someone = true;
			break;
		}
	}

	bool everyone_knows_celebrity = true;
	for (int i = 0; i < n; i++)
	{
		if (i == potential_celebrity) continue;
		if (a[i][potential_celebrity] == 0)
		{
			everyone_knows_celebrity = false;
			break;
		}
	}


	if (celebrity_knows_someone == false && everyone_knows_celebrity == true)
	{
		return potential_celebrity;
	}
	else return -1;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n;
		m = n;
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


		cout << find_celebrity(mat, n, m);
	}
	return 0;
}
