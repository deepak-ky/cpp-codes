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
		vector<vector<int>> mat = {
			{2},
			{3, 4},
			{6, 5, 7},
			{4, 1, 8, 3}
		};


		int n = mat.size();



		for (int i = n - 2; i >= 0; i--)
		{

			vector<int> w = mat[i];
			for (int j = 0; j < w.size(); j++)
			{
				int u = min(mat[i + 1][j] , mat[i + 1][j + 1]);
				w[j] += u;
			}

			for (int j = 0; j < w.size(); j++)
			{
				mat[i][j] = w[j];
			}
		}

		cout << mat[0][0] << endl;

	}
	return 0;
}
