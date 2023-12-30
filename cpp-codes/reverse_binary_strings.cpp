#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
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
	test
	{
		int n;
		cin >> n;
		string a;
		cin >> a;
		//make a boolean array and mark those positions where a change is needed
		int b[n];
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (i & 1)
			{
				//It is an odd position , I want the variable to not be equal to the first variable
				if (a[i] == a[0])
				{
					b[i] = 1;
				}
				else
				{
					b[i] = 0;

				}

			}
			else
			{
				//If it is an even position,  I want the variable to be equal to the first variable
				if (a[i] == a[0])
				{
					b[i] = 0;
				}
				else
				{
					b[i] = 1;

				}
			}


		}
		//find all the continous segments of 1
		for (int i = 1; i < n; i++)
		{
			if (b[i] == 1 && b[i - 1] != b[i])
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
