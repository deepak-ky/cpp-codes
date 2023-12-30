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
		string s;
		cin >> s;
		vector<char> v;
		unordered_map< char , bool > mp;
		for (int i = 0; i < s.length(); i++)
		{

			char ch = s[i];
			auto it = find(v.begin(), v.end(), ch);
			if (it == v.end() && mp[ch] == false)
			{
				mp[ch] = true;
				v.push_back(ch);
			}
			else if (it != v.end())
			{
				v.erase(it);
			}
		}
		if (v.size() == 0)
		{
			cout << -1 << endl;
		}
		else
		{

			string str = "";
			str += v[0];
			cout << str << endl;
			int pos = s.find(str);
			cout << pos << endl;
		}
	}
	return 0;
}
