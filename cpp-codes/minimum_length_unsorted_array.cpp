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
		int a[] = {1, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 18, 19};
		int n = sizeof(a) / sizeof(int);
		int *b = new int[n];
		//store two numbers at the current position -> one is that way
		for (int i = 0; i < n; i++)
		{
			b[i] = a[i];
		}
		sort(b, b + n);
		int start = -1;
		int end = -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] != b[i])
			{
				start = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] != b[i])
			{
				end = i;
				break;
			}
		}
		cout << start << " " << end << endl;

	}
	return 0;
}
