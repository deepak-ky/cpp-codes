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
	cin >> t;
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
		sort(a, a + n);
		int l = 0;
		int h = n - 1;
		int min_diff = INT_MAX;
		int a1, a2;
		while (l < h)
		{
			int w = a[l] + a[h];
			if (w == m)
			{
				int diff = a[h] - a[l];
				if (diff < min_diff)
				{
					min_diff = diff;
					a1 = a[l];
					a2 = a[h];
				}
				l++;
				h--;
			}
			else if (w > m)
			{
				h--;
			}
			else if (w < m)
			{
				l++;
			}
		}
		cout << "Deepak should buy roses whose prices are " << a1 << " and " << a2 << "." << endl;

	}
	return 0;
}
