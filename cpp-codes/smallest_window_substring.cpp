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
		string b;
		cin >> b;

		unordered_map<char, int> mp;
		for (int i = 0; i < b.length(); i++)
		{
			mp[b[i]]++;
		}

		string ans;
		int len = INT_MAX;


		unordered_map<char, int> big_map;

		int i = 0;
		int j = 0;
		int cnt = 0;

		while (j < a.length() /*&& i<=j*/)
		{


			char ch = a[j];
			big_map[ch]++;

			if (big_map[ch] <= mp[ch])
			{
				cnt++;
			}



			if (cnt == b.length())
			{


				//We have got a possible window substring


				while (mp[a[i]] == 0 || (big_map[a[i]] > mp[a[i]]))
				{
					if ( (big_map[a[i]] > mp[a[i]]))
					{
						//baad mein pta kaise chalega ki previous wala character occurence , discard hua hain ki nahi

						big_map[a[i]]--;   //VERY IMPT STEP.

					}
					i++;
				}

				string ty = a.substr(i, j - i + 1);
				cout << ty << endl;

				if (ty.length() < len)
				{
					len = ty.length();
					ans = ty;
				}
			}


			j++;

		}

		if (cnt == b.length())
		{
			//We have got a possible window substring


			while (mp[a[i]] == 0 || big_map[a[i]] > mp[a[i]])
			{
				i++;
			}

			string ty = a.substr(i, j - i + 1);
			cout << ty << endl;
		}


		cout << endl << endl;



		if (len == INT_MAX)
		{
			cout << "No window found";
		}
		else cout << ans;
		cout << endl;


	}
	return 0;
}
