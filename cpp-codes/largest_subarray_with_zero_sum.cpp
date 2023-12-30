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


		int a[] = {10, 5, -5, 4, -4, -10};
		int n = sizeof(a) / sizeof(int);

		int start = -1;
		int end = -1;
		int max_length = 0;


		unordered_map<int, int> mp;

		mp[0] = -1;

		int pre = 0;


		for (int i = 0; i < n; i++)
		{
			pre += a[i];

			if (mp.find(pre) == mp.end())
			{
				mp[pre] = i;
			}
			else
			{
				int len = i - (mp[pre] + 1) + 1;
				if (len > max_length)
				{
					start = mp[pre] + 1;
					end = i;
					max_length = len;
				}
			}

		}

		cout << endl;
		cout << "Largest Subarray with volume zero : \n";
		for (int i = start; i <= end; i++)
		{
			cout << a[i] << " ";
		}

	}
	return 0;
}
