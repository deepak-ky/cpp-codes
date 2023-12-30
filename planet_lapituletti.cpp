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

		vector<int> v;
		v.pb(0);
		v.pb(1);
		v.pb(2);
		v.pb(5);
		v.pb(8);


		mp[0] = 1;
		mp[1] = 2;
		mp[2] = 5;
		mp[3] = 5;
		mp[4] = 5;
		mp[5] = 8;
		mp[6] = 8;
		mp[7] = 8;
		mp[8] = 0;
		mp[9] = 0;


		int h, m;
		cin >> h >> m;

		string a;
		cin >> a;

		int h1 = a[0] - '0';
		int h2 = a[1] - '0';
		int m1 = a[3] - '0';
		int m2 = a[4] - '0';

		//closest hour to m1 , m2 is
		if (find(v.begin(), v.end() , m2) != v.end())
		{
			if (h <= 9)
			{

			}
			else
			{
				int r = m % 10;
				0236
				, LP
			}
		}
		else
		{

		}

	}
	return 0;
}
