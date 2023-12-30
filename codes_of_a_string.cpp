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
#define se                           second

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

unordered_map<string, string> mp;

vector<string> codes(string a, int idx, int n)
{

	vector<string> v;
	if (idx >= n)
	{
		// v.pb(" ");
		return v;
	}

	string s1 = "";  s1 = s1 + a[idx];  s1 = mp[s1];
	vector<string> vv = codes(a, idx + 1, n);
	if (vv.empty())
	{
		v.pb(s1);
	}
	else
	{
		for (int i = 0; i < vv.size(); i++)
		{
			v.pb(s1 + vv[i]);
		}
	}



	if (idx <= n - 2)
	{
		string s2 = "";
		s2 = s2 + a[idx] + a[idx + 1];
		if (mp.find(s2) != mp.end())
		{
			s2 = mp[s2];
			vector<string> vvv = codes(a, idx + 2, n);
			if (vvv.empty())
			{
				v.pb(s2);
			}
			else
			{
				for (int i = 0; i < vvv.size(); i++)
				{
					v.pb(s2 + vvv[i]);
				}
			}
		}

	}


	return v;

}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		for (int i = 1; i <= 26; i++)
		{
			string w = to_string(i);
			string s = "";
			char ch = 'a' + (i - 1) ;
			s = s + ch;
			mp[w] = s;

		}


		string a;
		cin >> a;
		vector<string> v;
		v = codes(a, 0, a.length());
		cout << "[";
		for (int i = 0; i < v.size() - 1; i++)
		{
			cout << v[i] << ", ";
		}
		cout << v[v.size() - 1] << "]";

	}
	return 0;
}
