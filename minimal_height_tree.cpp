#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second


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
	test
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//Make an height array of the vertices
		int height[n];
		//First element is at a height 0;
		height[0] = 0;

		//Second element will always be at a height 1
		height[1] = 1;

		int x = 0;
		for (int i = 2; i < n; i++)
		{
			if (a[i - 1] > a[i])
			{
				x++;
			}
			height[i] = height[x] + 1;
			//this line denotes that element at ith index is becoming a child of element at xth index and
			//hence its height would be x's height + 1
		}

		cout << height[n - 1] << endl;
	}
	return 0;
}
