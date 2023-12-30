#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int m = n;
	char mat[n][m];
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}
	if ( n == 1)
	{
		cout << "YES";
	}
	else
	{
		char ch1 = mat[0][0];
		char ch2 = mat[0][1];
		if (ch1 != mat[1][1] || ch1 != mat[2][2])
		{
			cout << "NO";
		}
		else if (ch2 != mat[1][0] || ch2 != mat[1][n - 1])
		{
			cout << "NO";
		}
		else if (ch1 == ch2)
		{
			cout << "NO";
		}
		else
		{
			int pos1 = 0;
			int pos2 = n - 1;
			for (int i = 0; i < n; i++)
			{
				if (mat[i][pos1] == ch1 && mat[i][pos2] == ch1)
				{
					for (int j = 0; j < n; j++)
					{
						if ((j != pos1) && (j != pos2) && (mat[i][j] != ch2))
						{
							flag = 1;
							break;
						}
					}
				}
				else
				{
					flag = 1;
					break;
				}
				pos2--;
				pos1++;
			}
			if (flag)
			{
				cout << "NO";
			}
			else cout << "YES";
		}
	}





	return 0;
}
