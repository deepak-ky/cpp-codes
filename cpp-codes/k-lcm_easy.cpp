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
		int w = n & (n - 1);
		if (n % 3 == 0)
		{
			cout << n / 3 << " " << n / 3 << " " << n / 3 << endl;
		}
		else if (n & 1)
		{
			cout << n / 2 << " " << n / 2 << " " << 1 << endl;
		}
		else if ((n / 2) & 1)
		{
			cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2 << endl;
		}
		else if ( w == 0)
		{

			cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
		}
		else
		{
			cout << n / 2 - 2 << " " << n / 2 - 2 << " " << 4 << endl;
		}

	}
	return 0;
}
