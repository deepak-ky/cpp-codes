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
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		bool all_a = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != 'a')
			{
				all_a = false;
				break;
			}
		}
		if (all_a)
		{
			no;
		}
		else
		{
			bool is_palindrom = false;
			int i = s.length() - 1;
			int ind = -1;
			while (i >= 0)
			{
				if (s[i] != 'a')
				{
					ind = i;
					break;
				}
				i--;

			}


			ind = s.length() - ind - 1;

			string part1 = s.substr(0, ind);
			string part2 = s.substr(ind, s.length() - ind);
			yes;
			cout << part1 + "a" + part2 << endl;


		}
	}
	return 0;
}
