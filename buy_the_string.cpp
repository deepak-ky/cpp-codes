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
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, c0, c1, h;
		cin >> n >> c0 >> c1 >> h;
		string s;
		cin >> s;
		int cnt_0 = 0;
		int cnt_1 = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '0')
			{
				cnt_0++;
			}
			else cnt_1++;
		}

		int op1 = cnt_0 * c0 + cnt_1 * c1;
		int op2 = cnt_0 * h  + cnt_0 * c1 + cnt_1 * c1;
		int op3 = cnt_0 * c0 + cnt_1 * h  + cnt_1 * c0;
		cout << min(op1, min(op2, op3)) << endl;

	}
	return 0;
}
