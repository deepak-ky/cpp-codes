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

		int m;
		cin >> m;
		int b[m];
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}

		int k;
		cin >> k;

		k--;


		bool flag = true;

		int i = 0;
		int j = 0;
		int w = 0;
		while (i < n && j < m)
		{
			if (a[i] <= b[j])
			{
				if (w == k)
				{
					flag = false;
					cout << a[i] << endl;
					break;
				}
				else
				{
					w++;
					i++;
				}
			}
			else
			{
				if (w == k)
				{
					flag = false;
					cout << b[j] << endl;
					break;
				}
				else
				{
					w++;
					j++;
				}
			}
		}

		if (flag)
		{
			while (i < n)
			{
				if (w == k)
				{
					flag = false;
					cout << a[i] << endl;
					break;
				}
				w++;
				i++;
			}
		}

		if (flag)
		{
			while (j < m)
			{
				if (w == k)
				{
					flag = false;
					cout << b[j] << endl;
					break;
				}
				w++;
				j++;
			}
		}

		if (flag) cout << -1 << endl;



	}
	return 0;
}
