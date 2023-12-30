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
int l, b;
void display_matrix(char mat[][50], int l, int b)
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}
}
void flood_fill(char mat[][50], int i, int j, char ch, char color)
{
	if (i < 0 || j < 0 || i >= l || j >= b)
	{
		return;
	}
	if (mat[i][j] != ch)
	{
		return;
	}
	mat[i][j] = color;
	flood_fill(mat, i - 1, j, ch, color);
	flood_fill(mat, i + 1, j, ch, color);
	flood_fill(mat, i, j - 1, ch, color);
	flood_fill(mat, i, j + 1, ch, color);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	cin >> l >> b;
	char mat[50][50];
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> mat[i][j];
		}
	}
	flood_fill(mat, 8, 13, '.', 'r');
	display_matrix(mat, l, b);
	return 0;
}
