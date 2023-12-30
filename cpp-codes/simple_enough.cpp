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

string  solve(int n)
{

	if (n == 0)
	{
		return "0";
	}
	if (n == 1)
	{
		return "1";
	}
	if (mp.find(n) != mp.end())
	{
		return mp[n];
	}
	string part_1 = solve(n / 2);
	string part_2 = solve(n % 2);
	//string part_3 = solve(n / 2);

	string ans = "";
	ans = ans + part_1 + part_2 + part_1;

	mp[n] = ans;
	return ans;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n, l, r;
		cin >> n >> l >> r;
		l--;
		r--;

		string w = solve(n);

		int cnt = 0;
		for (int i = l; i <= r; i++)
		{
			if (w[i] == '1')
			{
				cnt++;
			}
		}
		//cout << w << endl;
		cout << cnt << endl;

	}
	return 0;
}
