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
#define s                            second

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


class item
{
public:
	int weight;
	int index;

};
int32_t main()
{
	init();
	int t; cin >> t; while (t--)
	{
		int n, w;
		cin >> n >> w;
		vector<item> lesser;
		vector<int> middle;
		int small_total = 0;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a > w) continue;
			if (a >= (w + 1) / 2)
			{
				middle.pb(1);
				middle.pb(i + 1);
			}
			else
			{

				if (small_total + a <= w)
				{
					item y;
					y.weight = a;
					y.index = i + 1;
					lesser.pb(y);
					small_total += a;
				}

			}
		}
		if (middle.size() == 0 &&  lesser.size() == 0)
		{
			cout << -1 << endl;
		}
		else if (middle.size() > 0)
		{
			for (int i = 0; i < 2; i++)
			{
				cout << middle[i] << endl;
			}
		}
		else if (small_total >= (w + 1) / 2)
		{

			cout << lesser.size() << endl;
			for (auto x : lesser)
			{
				cout << x.index << " ";
			}
			cout << endl;

		}
		else
		{
			cout << -1 << endl;
		}
	}

	return 0;
}
