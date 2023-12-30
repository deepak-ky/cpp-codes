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
		int a[] = {2 , 4, 5, 7, 7, 6};
		int n = sizeof(a) / sizeof(int);
		int x = 6;
		int k = 2;


		int i = 0;
		bool flag = false;

		while (i < n)
		{
			if (a[i] == x)
			{
				flag = true;
				cout << i << endl;
				break;
			}
			else
			{
				int w = abs(a[i] - x);
				w = w / k;
				if (w <= 0)
				{
					i += 1;
				}
				else i += w;
			}

			wer(i);
		}

		if (!flag) cout << -1 << endl;
	}
	return 0;
}
