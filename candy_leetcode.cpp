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


		int left[n];
		int right[n];
		for (int i = 0; i < n; i++) {left[i] = right[i] = 1;}

		for (int i = 1; i < n; i++)
		{
			if (a[i] > a[i - 1])
			{
				left[i] = left[i - 1] + 1;
			}
		}

		for (int i = (n - 2); i >= 0; i--)
		{
			if (a[i] > a[i + 1])
			{
				right[i] = right[i + 1] + 1;
			}
		}

		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += max(left[i], right[i]);
		}

		cout << sum << endl;

	}
	return 0;
}
