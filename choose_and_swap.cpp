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
		string a;
		cin >> a;

		set<char> s;
		for (auto x : a)
		{
			s.insert(x);
		}

		bool flag = false;
		char ch1;
		char ch2;

		for (int i = 0; i < a.length(); i++)
		{
			s.erase(a[i]);
			if (s.empty())
			{
				break;
			}
			else
			{
				char ch = *s.begin();
				if (a[i] > ch)
				{
					flag = true;
					ch1 = a[i];
					ch2 = ch;
					break;
				}
			}
		}

		if (flag == true)
		{
			for (int i = 0; i < a.length(); i++)
			{
				if (a[i] == ch1)
				{
					a[i] = ch2;
				}
				else if (a[i] == ch2)
				{
					a[i] = ch1;
				}
				else continue;
			}
		}

		cout << a << endl;


	}
	return 0;
}


//aaabbdcaaabbb