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
		int n;
		cin >> n;
		int m;
		cin >> m;
		int *a = new int[n];
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[(a[i] % m)]++;
		}
		// for (auto x : mp)
		// {
		// 	cout << x.first << " " << x.second << endl;
		// }

		int ans = 0;
		if (mp[0] > 0) ans++;
		for (int i = 1; i <= m / 2; i++)
		{
			//wer(i);
			int w = m - i;
			if (mp[w] == 0)
			{
				ans += mp[i];
			}
			else if (i == w)
			{
				if (mp[i] > 0)
					ans += 1;
			}
			else
			{
				//I have two frequencies here
				int f1 = mp[i];
				int f2 = mp[w];
				if (f1 == 0)
				{
					//the number is not itself present
					ans += f2;
				}
				else
				{
					//f1 > 0 && f2 > 0
					if (f1 == f2) ans += 1;
					else
					{
						int f_min = min(f1, f2);
						int f_max = max(f1, f2);
						f_max -= f_min;
						ans += f_max;
					}
				}

			}
			//wer(ans);
		}

		cout << ans << endl;


	}







	return 0;
}
