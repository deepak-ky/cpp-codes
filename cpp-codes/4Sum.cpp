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
/*
bool have_not_repeated(int i,int j,int k,int l,unordered_map<string,bool> &mp2)
{
	int i_s = to_string(i);
	int j_s = to_string(j);
	int k_s = to_string(k);
	int l_s = to_string(l);
	string s = "";
	s += i_s;
	s += j_s;
	s += k_s;
	s += l_s;

	sort(s.begin(),s.end());

	if(mp.find(s))
}*/

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int diff;
		cin >> diff;

		unordered_map < int, list<pair<int, int>> > mp;

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int w = a[i] + a[j];
				mp[w].pb({i, j});
			}
		}

		for (auto x : mp)
		{
			cout << x.first << " : ";
			for (auto y : x.second)
			{
				cout << "{" << a[y.first] << "," << a[y.second] << " },";
			}

			cout << endl;
		}

		bool flag = false;
		//unordered_map<string,bool> mp2;
		set<vector<int>> s;

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int w = a[i] + a[j];
				int k = diff - w;
				if (mp.find(k) != mp.end())
				{
					//I have to check its every pair
					for (auto y : mp[k])
					{
						//For the unique condition
						if (i != y.first && i != y.second && j != y.first && j != y.second)
						{
							//if(have_not_repeated(a[i],a[j],a[y.f],a[y.se],mp2) == false)
							vector<int> v;
							v.push_back(a[i]);
							v.push_back(a[j]);
							v.push_back(a[y.first]);
							v.push_back(a[y.second]);
							sort(v.begin(), v.end());
							s.insert(v);

							//cout << a[i] << " " <<  a[j] << " " << a[y.first] << " " << a[y.second] << endl;

						}

					}
				}

			}

		}


		for (auto x : s)
		{
			for (auto y : x)
			{
				cout << y << " ";
			}
			cout << endl;
		}







	}
	return 0;
}
