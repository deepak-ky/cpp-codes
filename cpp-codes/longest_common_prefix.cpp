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

string shortest_common_prefix(vector<string> a)
{
	int n = a.size();
	string ans = "";
	int idx = 0;
	while (1)
	{
		if (idx == a[0].length()) break;
		char ch = a[0][idx];
		bool flag = false;
		for (int i = 1; i < n; i++)
		{
			if (idx == a[i].length())
			{
				flag = true;
				break;
			}

			if (a[i][idx] != ch)
			{
				flag = true;
				break;
			}


		}

		if (flag) break;

		ans += ch;
		idx++;
	}
	if (ans.length() == 0) return "-1";
	else return ans;
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
		vector<string> a;
		for (int i = 0; i < n; i++)
		{
			string w;
			cin >> w;
			a.push_back(w);
		}

		cout << shortest_common_prefix(a);

	}
	return 0;
}
