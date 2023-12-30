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
		vector<int> a1 = {1, 2};
		vector<int> a2 = { -2, -1};
		vector<int> a3 = { -1, 2};
		vector<int> a4 = {0, 2};

		int n = 2;

		unordered_map<int, int> mp1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mp1[a1[i] + a2[j]]++;
			}
		}

		unordered_map<int, int> mp2;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mp2[a3[i] + a4[j]]++;
			}
		}

		int ans = 0;

		for (auto x : mp1)
		{
			ans = ans + (x.second * mp2[-x.first]);
		}

		cout << ans << endl;

	}
	return 0;
}
