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

		int target;
		cin >> target;

		set<pair<int, int>> s;
		for (int i = 0; i < n; i++)
		{
			s.insert({a[i], i});
		}

		auto it1 = s.begin();
		auto it2 = s.end();
		it2--;
		bool flag = false;
		while (it1 != it2)
		{
			int x = it1->first;
			int y = it2->first;
			if ((x + y) == target)
			{
				flag = true;
				cout << it1->second << " " << it2->second << endl;
				break;
			}
			else if ((x + y) > target)
			{
				it2--;
			}
			else it1++;
		}
		if (flag == false)
		{
			cout << -1 << endl;
		}
	}

	return 0;
}
