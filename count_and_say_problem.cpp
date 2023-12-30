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

unordered_map<int, string> mp;

string say(string s)
{
	vector<int> v;
	int curr_cnt = 1;
	char prev_char = s[0];
	int i = 1;
	while (i < s.length())
	{
		if (s[i] != prev_char)
		{
			v.pb(curr_cnt);
			int e = prev_char - '0';
			v.pb(e);
			curr_cnt = 1;
			prev_char = s[i];

		}
		else
		{
			curr_cnt++;
		}
		i++;
	}
	v.pb(curr_cnt);
	int e = prev_char - '0';

	v.pb(e);

	string ans = "";
	for (int j = 0; j < v.size(); j++)
	{
		int y = v[j];
		char f = y + 48;
		ans += f;

	}
	return ans;

}


string count_and_say(int n)
{
	if (n == 1)
	{
		return "1";
	}
	string w;
	if (mp.find(n - 1) != mp.end())
	{
		w = mp[n - 1];
	}
	else
	{

		w = count_and_say(n - 1);
		mp[n - 1] = w;
	}

	string ans = say(w);
	return ans;
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

		cout << count_and_say(4);


	}
	return 0;
}
