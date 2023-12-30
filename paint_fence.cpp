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
		int k;

		cin >> n;
		cin >> k;

		if (n == 1)
		{
			cout << k << endl;
		}
		else
		{
			int last_two_same[n + 1];
			int last_two_different[n + 1];
			int total[n + 1];


			last_two_same[0] = last_two_same[1] = 0;
			last_two_different[0] = last_two_different[1] = 0;
			total[0] = total[1] = 0;

			last_two_same[2] = k;
			last_two_different[2] = k * (k - 1);
			total[2] = last_two_same[2] + last_two_different[2];


			for (int i = 3; i < n + 1; i++)
			{
				last_two_same[i] = last_two_different[i - 1];
				last_two_different[i] = total[i - 1] * (k - 1);

				total[i] = ((last_two_same[i] % mod) + (last_two_different[i] % mod)) % mod;
			}


			cout << total[n] % mod;

		}
	}
	return 0;
}
