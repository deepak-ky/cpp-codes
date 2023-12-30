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

		int notrans;
		cin >> notrans;


		unordered_map<string, int> mp;

		for (int i = 0; i < notrans; i++)
		{
			string a, b;
			cin >> a >> b;
			int m;
			cin >> m;

			mp[a] -= m;
			mp[b] += m;
		}


		multiset< pair<int, string> > ms;

		for (auto x : mp)
		{
			//cout << x.first << " : " << x.second << endl;
			ms.insert({x.second , x.first});
		}

		//maximum debit will suffice maximum credit
		while (!ms.empty())
		{
			auto it = ms.begin();
			auto it1 = ms.end();
			it1--;

			ms.erase(it);
			ms.erase(it1);

			int debit = (*it).first;
			int credit = (*it1).first;

			int max_abs = min( -debit , credit);

			cout << (*it).second << " will give " << max_abs << " to " << (*it1).second << endl;
			cout << endl;

			debit += max_abs;
			credit -= max_abs;



			if (debit != 0)
			{
				ms.insert({debit, (*it).second});
			}

			if (credit != 0)
			{
				ms.insert({credit , (*it1).second });

			}
		}





	}
	return 0;
}
