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


string sum_of_integers(string n)
{

	int ans = 0;
	for (int i = 0; i < n.length(); i++)
	{

		ans += n[i] - '0';

	}

	return to_string(ans);
}
int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int num = 1;
		unordered_map<char, string> mp;
		for (char ch = 'a'; ch <= 'z'; ch++)
		{
			mp[ch] = to_string(num);
			num++;
		}


		string s;
		cin >> s;

		int k;
		cin >> k;


		string w = "";


		for (auto x : s)
		{
			w += mp[x];

		}

		while (k > 0)
		{
			w = sum_of_integers(w);
			k--;
		}

		cout << w <<  endl;









	}
	return 0;
}
