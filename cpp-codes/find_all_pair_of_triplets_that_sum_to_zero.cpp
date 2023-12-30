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


		sort(a, a + n);


		vector<vector<int>> ans;

		set<vector<int>> s;

		for (int i = 0; i < n - 2; i++)
		{
			int j = i + 1;
			int k = n - 1;

			int sum = -a[i];

			while (j < k)
			{
				int w = a[j] + a[k];
				if (w == sum)
				{
					vector<int> v;
					v.push_back(a[i]);
					v.push_back(a[j]);
					v.push_back(a[k]);
					s.insert(v);
					int p1 = a[j];
					while (a[j] == p1)
					{
						j++;
					}
					int p2 = a[k];
					while (a[k] == p2)
					{
						k--;
					}

				}
				else if (w < sum)
				{
					j++;
				}
				else k--;
			}
		}
		for (auto x : s)
		{
			ans.push_back(x);
		}

		for (auto x : ans)
		{
			for (auto y : x)
			{
				cout << y << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
