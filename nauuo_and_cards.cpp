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
		vector<int> v;
		vector<int> q;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			v.pb(x);
		}
		vector<int> v1;
		for (int i = 1; i <= n; i++)
		{
			v1.pb(i);
		}
		if (q == v1) cout << 0 << endl;
		int ans1 = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			if (q[i])
			{
				ans1 = max(ans1 , i + 1 - q[i] + 1);
			}
		}
		ans1 += n;
		int ans2 = 0;

		int nn;
		while (q != v1)
		{
			if (q[n - 1] == n)
			{
				nn = 1;
			}
			else nn = q[n - 1] + 1;
			cout << nn << endl;

			//if it can be simply resovlved
			auto it = find(v.begin(), v.end() , nn);
			if (it != v.end())
			{
				int w = q[0];
				q.erase(v.begin());
				v.erase(it);
				v.pb(w);
				q.pb(nn);

			}
			else
			{
				auto it1 = find(v.begin(), v.end() , 0);

				int w = q[0];
				q.erase(v.begin());
				v.erase(it1);
				v.pb(w);
				q.pb(0);

			}
			ans2++;

		}
		cout << min(ans1, ans2);






	}
	return 0;
}
