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
		int n, k;

		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> stars;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '*')
			{
				stars.pb(i);
			}
		}

		int ans = 0;
		if (stars.size() <= 2)
		{
			cout << stars.size() << " " << endl;
		}
		else
		{
			int size = stars.size();
			int i = 0;
			int req_pos = stars[i] + k;
			int cnt = 0;
			int last_ans;
			i++;
			while (i < (size))
			{
				if (stars[i] <= req_pos)
				{
					last_ans = stars[i];
				}
				else if (stars[i] > req_pos)
				{
					cnt++;
					req_pos = last_ans + k;
					i--;
				}
				i++;

			}

			cout << cnt  + 2 << endl;
		}

	}
	return 0;
}
