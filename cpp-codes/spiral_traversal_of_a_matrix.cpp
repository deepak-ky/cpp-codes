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



		int sr = 0;
		int er = n - 1;
		int sc = 0;
		int ec = m - 1;
		int i = 0;
		int j = 0;
		while (sr <= er && sc <= ec)
		{
			if (i == sr)
			{
				for (int k = sc; k <= ec; k++)
				{
					cout << mat[i][k] << " ";
				}
				j = ec;
				sr++;
				cout << "|";
			}

			if (j == ec)
			{
				for (int k = sr; k <= er; k++)
				{
					cout << mat[k][j] << " ";
				}
				i = er;
				ec--;
				cout << "|";
			}

			if (er >= sr)
			{
				if (i == er)
				{
					for (int k = ec; k >= sc; k--)
					{
						cout << mat[i][k] << " ";
					}
					j = sc;
					er--;
					cout << "|";
				}
			}


			if (ec >= sc)
			{

				if (j == sc)
				{
					for (int k = er; k >= sr; k--)
					{
						cout << mat[k][j] << " ";
					}
					i = sr;
					sc++;
					cout << "|";
				}
			}



		}
	}
	return 0;
}
