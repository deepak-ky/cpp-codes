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
		int n, s, m;
		cin >>  n >> s >> m;

		//If we survive for the first 7 days , we can surive for any number of days
		//because after that it is reptitive only

		bool can_survive = true;

		if (n < m)
		{
			can_survive = false;
		}


		//If we buy food for the first 6 days is it , and they are enough for that day , do we have the remaining food added enough for the seventh day
		// seventh day is a sunday
		// I buy food for the first 6 days
		// amount of food that remains empty each day  (n - m)
		if (6 * (n - m) < m)
		{
			//If it is not enought we cannout surviv
			can_survive = false;
		}

		if (can_survive)
		{
			yes;
		}
		else no;


		//the above approach is similar to gfg
		//6 * n < 7 * m
		//6 * n < 6 * m  + m
		//6 * n - 6 * m < m
		//6 * (n - m ) < m
	}
	return 0;
}
