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

		unordered_map<int, int> mp;
		mp[0] = 1;
		for (int i = 1; i <= 9; i++)
		{
			mp[i] = i * mp[i - 1];
		}


		int n;
		cin >> n;

		int k;
		cin >> k;
		k--;

		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			v.push_back(i);
		}


		string ans = "";

		while (v.size() != 1)
		{
			int n = v.size();

			int n_minus_one_fact = mp[n - 1];

			int index = k / n_minus_one_fact;
			int rem = k % n_minus_one_fact;

			ans += to_string(v[index]);

			v.erase(v.begin() + index);

			k = rem;

		}

		ans += to_string(v[0]);

		cout << ans << endl;

	}
	return 0;
}
