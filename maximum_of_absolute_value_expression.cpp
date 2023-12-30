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
		vector<pair<int, int>> v = { {1, 1} , {1, -1} , { -1, 1} , { -1, -1}};

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int *b = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}


		int ans = INT_MIN;

		int j = 0;
		while (j < 4)
		{
			int sign1 = v[j].first;
			int sign2 = v[j].second;

			int mini = INT_MAX;
			int maxi = INT_MIN;

			for (int i = 0; i < n; i++)
			{
				int val = (a[i] * sign1) + (b[i] * sign2) + i;
				mini = min(mini, val);
				maxi = max(maxi, val);
			}


			ans = max(ans , (maxi - mini));

			j++;
		}


		cout << ans << endl;

	}
	return 0;
}
