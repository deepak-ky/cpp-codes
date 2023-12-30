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
	string s;
	cin >> s;
	string str = "^";
	int len = s.length();
	size_t found = s.find(str);
	int pos = found;
	//wer(pos);
	int sum = 0;
	for (int i = 0; i < pos; i++)
	{
		if (s[i] != '=')
		{
			int a = s[i] - '0';
			//wer(a);
			int dist = abs(i - pos);
			//wer(dist);
			sum += dist * a;
		}
	}
	int sum1 = 0;
	for (int i = pos + 1; i < len; i++)
	{
		if (s[i] != '=')
		{
			int a = s[i] - '0';
			//wer(a);
			int dist = abs(i - pos);
			//wer(dist);
			sum1 += dist * a;
		}
	}
	if (sum > sum1) cout << "left";
	else if (sum < sum1) cout << "right";
	else cout << "balance";


	return 0;
}
