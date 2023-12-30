
/*10
89134 65868 124951 351893 163416 115546 531401 6165 127617 15844*/


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
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;

		int *a = new int[n];
		int number_of_divisors = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			number_of_divisors = (((a[i] + 1) % mod) * (number_of_divisors % mod)) % mod;
			number_of_divisors %= mod;
		}
		wer(number_of_divisors);
		if (number_of_divisors % 2 == 0)
		{

			int pair_of_divisors = number_of_divisors / 2;
			for (int i = 0; i < n; i++)
			{
				a[i] = (a[i] % mod * pair_of_divisors % mod) % mod;
			}
			int answer = 1;
			for (int i = 0; i < n; i++)
			{
				answer = (((a[i] + 1) % mod) * (answer % mod)) % mod;
				answer %= mod;
			}
			cout << answer % mod;
		}
		else
		{
			int pair_of_divisors = number_of_divisors / 2;
			for (int i = 0; i < n; i++)
			{
				int w = a[i] / 2;
				w %= mod;
				a[i] = (a[i] % mod * pair_of_divisors % mod) % mod;
				a[i] = (a[i] % mod + w % mod) % mod;

			}
			int answer = 1;
			for (int i = 0; i < n; i++)
			{
				answer = (((a[i] + 1) % mod) * (answer % mod)) % mod;
				answer %= mod;
			}
			cout << answer % mod;
		}


	}
	return 0;
}

