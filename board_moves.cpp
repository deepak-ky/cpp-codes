#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			int totalmoves = 0;
			int value = n / 2;
			int imptmoves = 0;
			for (int i = 1; i <= n / 2; i++)
			{
				imptmoves = imptmoves + i;
			}
			wer(imptmoves);
			totalmoves += (imptmoves * 4);
			wer(totalmoves);
			int inoneindex = 0;
			for (int i = 1; i <= n / 2 ; i++)
			{
				inoneindex += (i * 4);
			}
			wer(inoneindex);
			totalmoves += (inoneindex );
			int finalmoves = 0 ;
			finalmoves += (imptmoves * 4);
			wer(finalmoves);
			totalmoves += finalmoves;
			cout << totalmoves << endl;

		}
	}
	return 0;
}
