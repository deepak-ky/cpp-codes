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

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.f >= p2.f)
	{
		return false;
	}
	else return true;

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		vector<pair<int, int> > v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.pb({a, b});
		}

		sort(v.begin(), v.end(), compare);

		//now I have to merge intervals
		pair<int, int> p = v[0];
		int curr_start_point = p.f;
		int end_point_now = p.se;
		vector<pair<int, int> > ans;

		int i = 1;
		while (i < n)
		{
			pair<int, int> p = v[i];
			//Three cases
			//First most important thing is
			if (p.f > end_point_now)
			{
				ans.pb({curr_start_point, end_point_now});
				curr_start_point = p.f;
				end_point_now = p.se;
			}
			else
			{

				curr_start_point = min(curr_start_point, p.f);
				end_point_now = max(end_point_now, p.se);
			}
			i++;
		}
		ans.pb({curr_start_point, end_point_now});



		for (auto x : ans)
		{
			cout << x.first << " " << x.second << endl;
		}
	}
	return 0;
}
