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


int up(int *a, int n, int key)
{
	int l = 0;
	int h = n - 1;
	int ans = -1;
	while (l <= h)
	{
		int m = l + ((h - l) / 2);
		if (a[m] > key)
		{
			ans = m;
			h = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	return ans;
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

		sort(a, a + n);

		int p_sum[n];
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			p = p + a[i];
			p_sum[i] = p;
		}


		int q;
		cin >> q;
		while (q--)
		{
			int k;
			cin >> k;

			int up_index = up(a, n, k);

			if (up_index == -1)
			{

				cout << n << " " << p_sum[n - 1] << endl;

			}
			else if (up_index == 0)
			{
				cout << 0 << " " << 0 << endl;
			}
			else
			{
				cout << up_index << " " << p_sum[up_index - 1] << endl;
			}
		}


	}
	return 0;
}
