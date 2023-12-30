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

bool compare(pair<int, int> p1 , pair<int, int> p2)
{
	if (p1.first <= p2.first)
	{
		return true;
	}
	else return false;
}

int lb(int *a, int n, int k)
{
	int l = 0;
	int h = n - 1;
	int ans = -1;
	while (l <= h)
	{
		int m = l + ((h - l) / 2);
		if (a[m] >= k)
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
		int n, q;
		cin >> n >> q;
		vector<pair<int, int> > v;

		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;

			v.pb({a, b});
		}

		//Convert the given pairs into no-overlapping and sorted pairs

		//sort on the basis of starting point
		sort(v.begin(), v.end() , compare);

		//Merge overlapping sub-intervals

		int starting_point = v[0].f;
		int ending_point = v[0].se;
		int i = 1;

		vector<pair<int, int>> p;

		p.pb({0, 0});

		while (i < n)
		{
			if (v[i].first <= ending_point)
			{
				ending_point = max(ending_point , v[i].se);
				i++;
			}
			else
			{
				p.pb({starting_point, ending_point});
				starting_point = v[i].f;
				ending_point = v[i].se;
				i++;
			}
		}

		p.pb({starting_point, ending_point});

		/*	for (auto x : p)
			{
				cout << x.first << " " << x.second << endl;
			}
		*/



		int w = p.size();

		int *arr = new int[w];


		arr[0] = 0;
		for (int i = 1; i < w; i++)
		{
			arr[i] = arr[i - 1] + (p[i].se - p[i].f + 1);
		}

		//out (arr, w);

		while (q--)
		{
			int k;
			cin >> k;




			if (k > arr[w - 1])
			{
				cout << -1 << endl;
			}
			else
			{
				int idx = lb(arr, w, k);


				cout << (k - arr[idx - 1]) + p[idx].f - 1 << endl;
			}

		}

	}
	return 0;
}