#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<int> closest_num;
		for (int i = 0; i < n; i++)
		{
			int q = a[i] / k;
			int r = a[i] % k;
			if (r == 0)
			{
				closest_num.push_back(0);
			}
			else
			{
				int w = (q + 1) * k - a[i];
				closest_num.push_back(w);
			}

		}
		/*	for (auto x : closest_num)
			{
				cout << x << " ";
			}*/

		bool flag = true;
		int s = 0;
		sort(closest_num.begin(), closest_num.end());

		for (int i = 0; i < n; i++)
		{
			if (closest_num[i] != 0)
			{
				s = i;
				flag = false;
				break;
			}
		}
		if (flag) cout << 0 << endl;
		else
		{
			map<int, bool> visited;
			map<int, int> mp;
			int ans = INT_MIN;
			for (int i = s; i < n; i++)
			{
				if (visited[closest_num[i]] == false)
				{
					visited[closest_num[i]] = true;
					mp[closest_num[i]] = closest_num[i];
				}
				else mp[closest_num[i]] += k;
				ans = max(mp[closest_num[i]], ans);
			}
			cout << ans + 1 << endl;
		}
	}
	return 0;
}
