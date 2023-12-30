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

		int a[] = {1};
		int n = sizeof(a) / sizeof(int);


		if (n == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			int max_ladder_length = a[0];
			int stairs = a[0];
			int min_jumps_req = 1;
			for (int i = 1; i < n; i++)
			{
				//reached the last index
				if (i == n - 1)
				{
					cout << min_jumps_req << endl;
					break;
				}

				max_ladder_length = max(max_ladder_length , i + a[i]);
				stairs--;



				if (stairs == 0)
				{
					min_jumps_req++;
					stairs = max_ladder_length - i;
				}
				if (stairs <= 0)
				{
					cout << -1;
					break;
				}
			}
		}

	}
	return 0;
}
