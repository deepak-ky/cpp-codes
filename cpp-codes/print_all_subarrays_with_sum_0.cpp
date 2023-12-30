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

		unordered_map<int, list<int>> mp;
		int cnt = 0;
		mp[0].pb(-1);
		int p_sum = 0;
		for (int i = 0; i < n; i++)
		{
			p_sum += a[i];
			if (mp.find(p_sum) != mp.end())
			{
				cnt += mp[p_sum].size();
				for (auto x : mp[p_sum])
				{
					for (int j = x + 1; j <= i; j++)
					{
						cout << a[j] << " ";
					}
					cout << endl;
				}

			}
			mp[p_sum].push_back(i);
		}

		cout << cnt << endl;
	}
	return 0;
}
