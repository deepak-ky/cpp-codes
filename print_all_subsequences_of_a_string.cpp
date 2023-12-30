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

map<string, int> mp;
multiset<string> s;

string cal(string a, int n)
{
	string ans = "";
	int i = 0;
	while (n > 0)
	{
		if (n & 1)
		{
			ans += a[i];
		}
		i++;
		n = n >> 1;
	}
	return ans;
}

void subsequences(string a)
{
	//Total number of subsequences
	int n = a.length();
	int cnt = pow(2, n);


	for (int i = 0; i < cnt; i++)
	{
		string w = cal(a, i);
		s.insert(w);
		mp[w]++;
	}
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string a;
		cin >> a;

		subsequences(a);



		//All subsequences

		cout << "All subsequences : ";
		cout << endl;
		for (auto x : s)
		{
			cout << x;
			cout << endl;
		}


		//Distinct Subsequences

		cout << "Distinct Subsequences : ";
		cout << endl;
		for (auto x : mp)
		{
			cout << x.first << endl;
		}
	}

	return 0;
}
