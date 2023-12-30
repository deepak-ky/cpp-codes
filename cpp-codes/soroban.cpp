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
	string s[10];
	s[0] = "O-|-OOOO";
	s[1] = "O-|O-OOO";
	s[2] = "O-|OO-OO";
	s[3] = "O-|OOO-O";
	s[4] = "O-|OOOO-";
	s[5] = "-O|-OOOO";
	s[6] = "-O|O-OOO";
	s[7] = "-O|OO-OO";
	s[8] = "-O|OOO-O";
	s[9] = "-O|OOOO-";
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << s[0];
	}
	else
	{
		while (n > 0)
		{
			int r = n % 10;
			cout << s[r] << endl;
			n = n / 10;
		}
	}


	return 0;
}
