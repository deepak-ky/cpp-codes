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

int find_index(vector<int> v, int key)
{
	int l = 0;
	int h = v.size() - 1;
	int ans = -1;
	while (l <= h)
	{
		int m  = (l + (h - l) / 2);
		if (v[m] == key)
		{
			return m;
			break;
		}
		else if (v[m] > key)
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
		int q;
		cin >> q;
		unordered_map<int, int> mp;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[a[i]] = i;
		}
		vector<int> v;
		int j = 0;
		v.pb(a[j]);
		for (int i = 1; i < n; i++)
		{
			if (a[i] > v[j])
			{
				v.pb(a[i]);
				j++;
			}
		}
		while (q--)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				int b;
				cin >> b;
				if (b <= v[0])
				{
					cout << mp[v[0]] << " ";
				}
				else if (b > v[v.size() - 1])
				{
					cout << -1  << " ";
				}
				else
				{
					int idx = find_index(v, b);
					cout << idx << " ";
				}

			}
			else if (a == 0)
			{
				int b, c;
				cin >> b;
				cin >> c;

				cout << a[b];
				// auto it = mp.find(prev);
				// mp.erase(it);
				// mp[c] = b;
			}
		}

	}
	return 0;
}
