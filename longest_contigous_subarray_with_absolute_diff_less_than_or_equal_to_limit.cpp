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


void display_set(multiset<pair<int, int>> s)
{
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << "{" << it->first << " , " << it->second << "}";
	}
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
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int limit;
		cin >> limit;
		wer(limit);
		multiset< pair<int, int> > s;
		int l = 0;
		int h = 1;
		s.insert({a[l], 0});
		int ans = 1;
		while (h < n)

		{
			wer(h);
			//between any two elements
			auto it = s.begin();
			int mi = it->first;
			int pos = it->second;
			auto it1 = s.end();
			it1--;
			int ma = it1->first;
			int pos1 = it1->second;
			int op1 = abs(a[h] - mi);
			int op2 = abs(a[h] - ma);
			cout << "op1 : " << op1 << endl;
			cout << "op2 : " << op2 << endl;
			if (((abs(a[h] - mi)) <= limit) && ((abs(a[h] - ma)) <= limit) )
			{
				s.insert({a[h], h});
				ans = max(ans, h - l + 1);
				h++;
			}
			else
			{
				//either it could start a new subarray or, coincide with the previous from some other point
				while (!s.empty())
				{
					auto it = s.begin();
					int mi = it->first;
					int pos = it->second;
					auto it1 = s.end();
					it1--;
					int ma = it1->first;
					int pos1 = it1->second;
					if (((abs(a[h] - mi)) > limit) || ((abs(a[h] - ma)) > limit) )
					{
						s.erase(it);
					}
					else
					{
						break;
					}
				}
				if (s.empty())
				{
					l = h;
					s.insert({a[h], h});
					ans = max(ans, h - l + 1);
				}
				else
				{
					auto it = s.begin();
					int pos = it->second;
					l = pos;
					s.insert({a[h], h});
					ans = max(ans, h - l + 1);

				}
				h++;

			}

			cout << "Set here : ";
			display_set(s);
			cout << endl;
		}

		cout << ans << endl;


	}
	return 0;
}
