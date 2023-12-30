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

int max_score(int *a, int l, int h, int n, int **mat)
{
	if (l > h)
	{
		return 0;
	}
	if (mat[l][h] != -1)
	{
		return mat[l][h];
	}
	int op1 = a[l] + min( max_score(a, l + 2, h, n, mat) , max_score(a, l + 1, h - 1, n, mat));
	int op2 = a[h] + min( max_score(a, l, h - 2, n, mat) , max_score(a, l + 1, h - 1, n, mat));
	int ans = max(op1, op2);
	return mat[l][h] = ans;
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
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int **mat = new int*[n];
		int m = n;
		for (int i = 0; i < n; i++)
		{
			mat[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = -1;
			}
		}

		cout << max_score(a, 0, n - 1, n, mat);

	}
	return 0;
}
