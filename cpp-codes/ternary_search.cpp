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

int ternary_search(int *a, int n, int k)
{
	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		int m1 = l + ((r - l) / 3);

		//divide the total length by 3 (divide the length into three parts) and add one part to the left starting point

		int m2 = r - ((r - l) / 3);

		//divide the total length by 3 (divide the length into three parts) and subtract one part to the right ending point.

		if (a[m1] == k) return m1;

		if (a[m2] == k) return m2;



		if (k < a[m1])
		{
			r = m1 - 1;
		}
		else if (k > a[m2])
		{
			l = m2 + 1;
		}
		else
		{
			l = m1 + 1;
			r = m2 - 1;
		}


	}


	return -1;
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


		int k;
		cin >> k;

		int w = ternary_search(a, n, k);
		if (w != -1)
		{
			cout << k << " is present in the array at index " << w << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
