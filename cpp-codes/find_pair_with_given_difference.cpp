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

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			mp[a[i]]++;
		}

		int diff;
		cin >> diff;

		bool flag = false;


		for (int i = 0; i < n; i++)
		{
			//suppose my current element is b , then these two following cases can arise
			//either x - b = diff => x = diff + b;
			// or    b - x = diff => x = b - diff;

			//for the duplicate element case
			mp[a[i]]--;

			if (mp[diff + a[i]] != 0)
			{
				flag = true;
				cout << diff +  a[i] << " " << a[i] << endl;
				break;
			}
			else if (mp[a[i] - diff] != 0)
			{
				flag = true;
				cout << a[i] << " " << a[i] - diff << endl;
				break;
			}
			mp[a[i]]++;
		}

		if (!flag) cout << -1 << endl;

	}
	return 0;
}
