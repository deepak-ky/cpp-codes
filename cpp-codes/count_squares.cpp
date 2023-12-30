#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//#define int                          long long
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

long long  binary_search_square(long long  n)
{
	long long  l = 1;
	long long  h = n;

	long long  ans = -1;

	while (l <= h)
	{
		long long mid = l + ((h - l) / 2);
		if ((mid * mid) <= n)
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			h = mid - 1;

		}
	}


	return ans;
}

int/*32_t*/ main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		//1 ,4 ,9 ,16 ,25 ,36 ,49 ,64
		int n;
		cin >> n;

		long long  w = binary_search_square((long long)n);
		wer(w);

		if ((w * w) == n)
		{
			cout << w - 1 << endl;
		}
		else cout << w << endl;
	}
	return 0;
}
