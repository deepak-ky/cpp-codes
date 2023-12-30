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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int r, c;
	cin >> r >> c;
	int **a;
	a = new int*[r]; //Create an array of row heads
	//create an 2-d array
	for (int i = 0; i < r; i++)
	{
		a[i] = new int[c];
	}
	int val = 1;
	//take input or print elements
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = val;
			val++;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}
