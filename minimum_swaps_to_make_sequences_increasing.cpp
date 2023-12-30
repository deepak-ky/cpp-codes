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

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int b[n];
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}

		int swaps[n];
		int no_swaps[n];

		swaps[0] = 1;
		no_swaps[0] = 0;

		for (int i = 1; i < n; i++)
		{
			swaps[i] = INT_MAX;
			no_swaps[i] = INT_MAX;

			if (a[i] > a[i - 1] && b[i] > b[i - 1])
			{
				no_swaps[i] = no_swaps[i - 1];
				swaps[i] = swaps[i - 1] + 1;
			}


			if (a[i] > b[i - 1] && b[i] > a[i - 1])
			{
				no_swaps[i] = min (  no_swaps[i] , swaps[i - 1] );
				swaps[i] =  min ( swaps[i] , no_swaps[i - 1] + 1 );
			}
		}

		cout << min(no_swaps[n - 1], swaps[n - 1]);




	}
	return 0;
}
