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

int cntpath(char **mat, int row, int col, int i, int j)
{
	if (i < 0 || j < 0)
	{
		return 0;
	}
	if (i == 0 || j == 0)
	{
		return 1;
	}
	if (mat[i][j] == 'X')
	{
		return 0;
	}
	int a = cntpath(mat, row, col, i - 1, j);
	int b = cntpath(mat, row, col, i, j - 1);
	return a + b;
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
		int c = cntpath(mat, n, m, n - 1 , m - 1);
		cout << c << endl;


	}
	return 0;
}
