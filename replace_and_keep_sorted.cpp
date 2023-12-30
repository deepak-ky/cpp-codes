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
		int q, k;
		cin >> q >> k;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int *start = new int[n];
		int *end = new int[n];
		int *mid = new int[n];
		start[n - 1] = -1;
		end[0] = -1;
		mid[0] = mid[n - 1] = 0;
		for (int i = 0; i < n - 1; i++)
		{
			start[i] = a[i + 1] - 2;
		}
		for (int i = 1; i < n; i++)
		{
			end[i] = k - a[i - 1]  - 1;
		}
		for (int i = 1; i < n - 1; i++)
		{
			mid[i] = a[i + 1] - a[i - 1] - 2;
		}

		while (q--)
		{
			int b, c;
			cin >> b >> c;
			b--;
			c--;
			int cnt = 0;
			if (b == c)
			{
				cnt = k - 1;
			}
			else
			{
				for (int i = b; i <= c; i++)
				{
					if (i == b)
					{
						cnt += start[i];
					}
					else if (i == c)
					{
						cnt += end[i];
					}
					else
					{
						cnt += mid[i];
					}
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
