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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int currpos;
	cin >> currpos;
	cout << "Initial position : " << currpos << endl;
	int t = 3;
	while (t--)
	{
		int pos1, pos2;
		cin >> pos1 >> pos2;
		if (pos1 == currpos)
		{
			currpos = pos2;
		}
		else if (pos2 == currpos)
		{
			currpos = pos1;
		}
		else currpos = currpos;

	}
	cout << currpos;

	return 0;
}
