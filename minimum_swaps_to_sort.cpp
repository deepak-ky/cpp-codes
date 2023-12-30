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

		unordered_map<int, int> mp1;
		for (int i = 0; i < n; i++)
		{
			mp1[a[i]] = i;
		}


		int *b = new int[n];
		for (int i = 0; i < n; i++)
		{
			b[i] = a[i];
		}

		sort(b, b + n);


		int min_swaps = 0;
		for (int i = 0; i < n; i++)
		{
			wer(i);
			if (a[i] == b[i])
			{
				continue;
			}
			else
			{
				int org_number = a[i];
				int org_index = mp1[b[i]];
				swap(a[i] , a[org_index]);
				mp1[b[i]] = i;
				mp1[org_number] = org_index;
				min_swaps++;
			}

			out(a, n);
			wer(min_swaps);

		}

		out(b, n);
		out(a, n);
		cout << min_swaps << endl;
	}
	return 0;
}
