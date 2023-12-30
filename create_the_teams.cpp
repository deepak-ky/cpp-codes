#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n, k;
		cin >> n >> k;
		vector<int> v;
		int total_teams = 0;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			if (w >= k)
				total_teams++;
			else
				v.push_back(w);
		}
		if (v.size() > 0)
		{
			int no_of_people_left = v.size();
			sort(v.begin(), v.end(), greater<int> ());
			// for (auto x : v)
			// {
			// 	cout << x << " ";
			// }
			/*cout << endl;*/
			int a[no_of_people_left];
			for (int i = 0; i < no_of_people_left; i++)
			{
				int w = v[i];
				int q = k / w;
				int r = k % w;
				if (r == 0)
				{
					a[i] = q;
				}
				else
				{
					a[i] = q + 1;
				}
			}
			// for (auto x : a)
			// {
			// 	cout << x << " ";
			// }
			// cout << endl;
			int i = 0;
			int no_of_people_till_now = 1;
			while ( i < no_of_people_left)
			{

				if (a[i] <= no_of_people_till_now)
				{
					total_teams++;
					no_of_people_till_now = 1;
					i++;
				}
				else
				{
					no_of_people_till_now++;
					i++;
				}
			}
		}
		cout << total_teams << endl;
	}
	return 0;
}
