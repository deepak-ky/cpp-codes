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
#define s                            second

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
	int t; cin >> t; while (t--)
	{
		int n, m;
		cin >> n >> m;
		int to_be_negative = INT_MAX;
		int total_value = 0;
		int negative_value = 0;
		bool has_zero = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int w;
				cin >> w;
				total_value += abs(w);
				to_be_negative = min(to_be_negative, abs(w));

				if (w < 0)
				{
					negative_value++;

				}
				if (w == 0)
				{
					has_zero = true;
				}


			}
		}
		//wer(negative_value);

		if (negative_value % 2 == 0 || has_zero)
		{
			cout << total_value << endl;
		}
		else
		{

			cout << total_value - 2 * to_be_negative << endl;
		}

	}
	return 0;
}
