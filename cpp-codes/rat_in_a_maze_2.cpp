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
const int n = 4;

void print_solution_path(int maze[][n], int i, int j, string path)
{
	if (i >= n || j >= n)
	{
		return;
	}
	if (maze[i][j] == 0)
	{
		return;
	}
	if (i == n - 1 && j == n - 1)
	{
		for (int i = 0; i < path.length(); i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}
	print_solution_path(maze, i, j + 1, path + "R");
	print_solution_path(maze, i + 1, j, path + "D");
	return;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int maze[n][n] = { { 1, 1, 1, 1 },
			{ 1, 1, 0, 1 },
			{ 1, 1, 1, 0 },
			{ 1, 0, 1, 1 }
		};

		//Here 1 - > block



		print_solution_path(maze, 0, 0, "");







	}
	return 0;
}
