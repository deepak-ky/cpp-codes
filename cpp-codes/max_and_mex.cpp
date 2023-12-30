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
		int n, k;
		cin >> n >> k;
		int a[n];

		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[a[i]]++;
		}

		sort(a, a + n);

		int maxx = *max_element(a, a + n);

		int i = 0;
		int cnt = 0;
		while (i < n)
		{
			if (a[i] == cnt)
			{
				cnt++;
			}
			i++;
		}

		int w = (maxx + cnt + 1) / 2;
		if (k == 0)
		{
			cout << mp.size() << endl;
		}
		else if (cnt == maxx + 1)
		{
			cout << mp.size() + k << endl;
		}
		else
		{
			mp[w]++;
			cout << mp.size() << endl;
		}

	}
	return 0;
}
