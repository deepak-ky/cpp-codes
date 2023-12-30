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


		int x;
		cin >> x;

		int ans = INT_MAX;
		int curr_sum = 0;
		int i = 0;
		int j = 0;
		while (j < n)
		{
			curr_sum += a[j];

			if (curr_sum > x)
			{
				ans = min (ans , (j - i + 1));
				while (i <= j)
				{
					if ((curr_sum - a[i]) > x)
					{
						curr_sum -= a[i];
						i++;
					}
					else  break;

				}

				ans = min(ans , (j - i + 1));
			}
			j++;
		}


		if (ans == INT_MAX)  cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
