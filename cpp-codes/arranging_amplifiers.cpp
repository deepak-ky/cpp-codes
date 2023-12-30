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


		//1 can be loaded many times , and rest all numbers can be loaded only once
		// , please make the statement more clear

		int n;
		cin >> n;

		int a[n];

		vector<int> v;

		set<int> s;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			s.insert(x);
			a[i] = x;
		}



		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1) v.push_back(1);
		}



		if (s.find(1) != s.end())
		{
			//v.push_back(1);
			s.erase(1);
		}

		if (!s.empty())
		{
			auto it = s.end();
			it--;
			if ((*it) <= 3)
			{
				while (!s.empty())
				{
					auto it = s.begin();
					v.push_back(*it);
					s.erase(it);
				}
			}
			else
			{
				while (!s.empty())
				{
					auto it = s.end();
					it--;
					v.push_back(*it);
					s.erase(it);
				}
			}
		}

		for (auto x : v)
		{
			cout << x << " ";
		}

		cout << endl;

	}
	return 0;
}
