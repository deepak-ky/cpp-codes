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
		int p, a, b, c;
		cin >> p >> a >> b >> c;
		if ((p % a == 0) || (p % b == 0) || (p % c == 0))
		{
			cout << 0 << endl;
		}
		else
		{
			int op1 = (((p / a) + 1) * a) - p;
			int op2 = (((p / b) + 1) * b) - p;
			int op3 = (((p / c) + 1) * c) - p;
			cout << min(op1, min(op2, op3)) << endl;
		}
	}
	return 0;
}
