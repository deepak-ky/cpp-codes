#include<iostream>se
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
	int mat[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> mat[i][j];
		}
	}
	int ii;
	int jj;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (mat[i][j] == 1)
			{
				ii = i;
				jj = j;
				break;
			}
		}
	}
	int steps_t = abs(ii - 2);
	int steps = abs(jj - 2);
	cout << steps + steps_t;
	return 0;
}
