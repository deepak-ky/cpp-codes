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

		/*
		1
		2
		3
		4
		5
		6
		7
		8
		9
		10
		11
		12
		13
		14
		15
		16
		17
		18
		19
		20
		21
		22
		23
		24
		*/
		int a[2][3][4];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					cin >> a[i][j][k];
				}
			}
		}



		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					cout <<  a[i][j][k] << " ";
				}
				cout << endl;
			}

			cout << endl << endl;
		}
	}
	return 0;
}
